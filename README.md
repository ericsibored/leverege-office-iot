# leverege-office-iot

Particle Photon firmware for BME280 sensor. This program will publish data to Particle Cloud & save temperature and humidity values as variables to be read in later by IFTTT.

## Usage
Set up the hardware:
- Particle Photon
- Adafruit BME280

## Flash Program to Microcontroller
- Go to build.particle.io
- Copy/paste this program
- Manually include the <Adafruit_BME280.h> library into your program tab if flashing over the air
- Program will not successfully flash if you do not complete this step!
## Particle Integration with IFTTT
- Create an account with IFTTT
- Nagivate to https://ifttt.com/create
- Click "+this" to begin creating a new applet
- Search and select "Particle" under Services

## Slack Integration with IFTTT
- Create a Slack account or use existing Slack account credentials
- Click "+that" and search "Slack" under services to set it up as an output
- Authorize access & choose your notification option (channel message or direct message)


## License
Eric Zhang, Leverege Systems Engineer, 2018
