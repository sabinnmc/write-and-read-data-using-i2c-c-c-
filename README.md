# AT24C01C/AT24C02C Serial EEPROM
## Two-Wire (I²C) Serial EEPROM: 1-Kbit (128 x 8) / 2-Kbit (256 x 8)

### Overview
The AT24C01C/AT24C02C provides 1024/2048 bits of serial electrically erasable and programmable read-only memory (EEPROM) organized as 128/256 words of 8 bits each. These devices are optimized for use in many industrial and commercial applications where low-power and low-voltage operation are essential.

### Key Features
- Memory Organization:
  - AT24C01C: 128 x 8 (1-Kbit)
  - AT24C02C: 256 x 8 (2-Kbit)
- Two-wire Serial Interface (I²C Compatible)
- Low-voltage Operation:
  - 1.8V to 5.5V
- Operating Temperature: -40°C to +85°C
- Endurance: 1 Million Write Cycles
- Data Retention: 100 Years
- Page Write Mode:
  - 8-byte Page Write Buffer
- Hardware Write Protection
- Fast Write Cycle Time: 5ms (typical)

### Pin Configuration
1. A0-A2: Address Inputs
2. SDA: Serial Data
3. SCL: Serial Clock
4. WP: Write Protect
5. VCC: Power Supply
6. GND: Ground

### Communication Protocol
- Two-wire Serial Interface:
  - Serial Data (SDA)
  - Serial Clock (SCL)
- Clock Frequency: up to 400 kHz
- Start/Stop Conditions for Data Transfer
- Acknowledge Bit After Each Byte

### Write Operations
1. Byte Write
   - Single byte writing at specified address
2. Page Write
   - Up to 8 bytes can be written in one operation
   - Automatic address increment
3. Write Protection
   - Hardware write protect pin (WP)
   - Software write protection available

### Read Operations
1. Current Address Read
   - Reads from current address pointer
2. Random Read
   - Reads from specified address
3. Sequential Read
   - Continuous read operation
   - Automatic address increment

### Device Addressing
- Device Address Format: 1010xxx0 (Read)
- Device Address Format: 1010xxx1 (Write)
- xxx: Hardware Address Pins (A2, A1, A0)

### Timing Specifications
- SCL Clock Frequency: 400 kHz max
- Start Hold Time: 0.6µs min
- Data Setup Time: 100ns min
- Data Hold Time: 300ns min
- Write Cycle Time: 5ms typ

### Application Guidelines
1. Power Supply Decoupling
   - Use 0.1µF ceramic capacitor
   - Place close to VCC pin

2. Pull-up Resistors
   - Required on SDA and SCL
   - Typical values: 4.7kΩ to 10kΩ

3. Write Protection
   - Connect WP to GND for normal operation
   - Connect WP to VCC for write protection

### Safety Considerations
- Observe proper ESD protection procedures
- Follow recommended operating conditions
- Ensure proper power supply sequencing

### Package Options
- 8-lead PDIP
- 8-lead SOIC
- 8-lead TSSOP
- 5-lead SOT23

### Related Documents
- Datasheet
- Application Notes
- Technical Reference Manual

### Ordering Information
Contact manufacturer or authorized distributors for:
- Package options
- Temperature ranges
- Quantity requirements

---
For detailed specifications and timing diagrams, please refer to the official datasheet.