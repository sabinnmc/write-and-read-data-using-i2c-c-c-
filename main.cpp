/**
 * @file main.cpp
 * @author sabin bhandari
 * @brief 
 * @version 1.0
 * @date 2024-11-13
 * 
 * @copyright Copyright (c) 2024
 * @ref AT24C01C/AT24C02C "i2c serial EEPROM"
 */

//******************************************************
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdint.h>         //comtain uin8_t
#include <unistd.h>         // write read close function are defined

#define SLAVE_ADDRESS           0x50
#define I2C_BUS_PATH            "/dev/i2c-2"
#define REGISTER_ADDRESS        0x00

bool intialization_i2c();
bool write_data_eeprom(uint8_t *data, size_t data_length);
bool read_data_eeprom(uint8_t *data);

int g_fd = 0;
int main()
{
    if(!intialization_i2c())
    {
        return -1;
    }

    //writing data 
    uint8_t data[] = {0x12, 0xFF, 0xA1};

    //writing data in memory
    //bool write_data_eeprom(uint8_t *data)
      //adding data on the same pipeline for data manipulation
    size_t data_length =  sizeof(data);
    if(write_data_eeprom(data, data_length))
    {
        printf("data written succefully \n");
    }
    else{
        perror("failed to write ");
        return -1;
    }

    uint8_t read_buffer[3];
    if(read_data_eeprom(read_buffer)){
        printf("data read successful !\n");
        printf("data read:: 0x%02x 0x%02x 0x%02x \n", read_buffer[0], read_buffer[1], read_buffer[2]);
        
    }
    else{
        printf("failed to read \n");
        return -1;
    }
    close(g_fd);
    return 0;
}

//intilaizing I2C communication 
bool intialization_i2c()
{
    g_fd = open(I2C_BUS_PATH, O_RDWR);
    
    if (g_fd < -1)
    {
        printf("open('%s') cannot be opned ! check  command --->>> ls /dev/i2c-1", I2C_BUS_PATH);
        close(g_fd);
        return false;
    }
    
    if(ioctl(g_fd, I2C_SLAVE, SLAVE_ADDRESS) < 0)
    {
        perror("failed to acquire i2c bus or failed to talk to slave");
        close(g_fd);
        return false;
    }
    return true;
}

bool write_data_eeprom(uint8_t *data, size_t data_length)
{
  
    int length = static_cast<int>(data_length);
    uint8_t buffer[length + 1];  // as data_lenth is unsigned long integer which cause problem 
    buffer[0] = REGISTER_ADDRESS;
    int i;
    for (i = 0; i < length ; i++){
        buffer[i+1] = data[i];
        // this is done to include both registeraddress and data on a single array line
    }
    printf("total memory used for writing is %ld \n", i*sizeof(buffer[0]));
    printf("value of file descriptor :: %d  \n", g_fd);

     if(ioctl(g_fd, I2C_SLAVE, SLAVE_ADDRESS) < 0)
    {
        perror("failed to acquire i2c bus or failed to talk to slave \n");
        close(g_fd);
        return false;
    }

    //ssize_t write(int fd, const void *buf, size_t count);
    ssize_t wr = write(g_fd, buffer, data_length + 1);
    printf("return value of write function pointer %zd \n ", wr);

    if(wr == static_cast<ssize_t>(data_length + 1))
    {
        printf("successflly writtwen to the I2C bus \n");
        //waiting write cycle to complete
        usleep(5000);
        return true;
    }
    else{
        perror("coulnot write to the I2C bus \n");
        return false;
    }
}

//reading data from a eeprom 
bool read_data_eeprom(uint8_t *data)
{
    if(ioctl(g_fd, I2C_SLAVE, SLAVE_ADDRESS) < 0)
    {
        perror("failed to acquire i2c bus or failed to talk to slave \n");
        close(g_fd);
        return false;
    }
    uint8_t reg_add[] = {REGISTER_ADDRESS};
    //@‡@@writing register address before 
    //@‡A@reading data from that register address
    if(write(g_fd, &reg_add, 1) != 1){
        perror("failed to write to the I2C bus");
        return false;
    }

    if(read(g_fd, data, sizeof(data)) != sizeof(data)){
        perror("failed to read from I2C bus");
        return false;
    }
    return true;
}
















































































































































































    

}