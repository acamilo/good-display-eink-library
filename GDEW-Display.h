#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
 
#include <Adafruit_GFX.h>
#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif

class GD_EinkDisplay : public Adafruit_GFX {
	public:
		GD_EinkDisplay(uint8_t sda, uint8_t scl, uint8_t ncs, uint8_t ndc, uint8_t nrst, uint8_t nbusy);
		boolean begin();
		void drawPixel(int16_t x, int16_t y, uint16_t color);
		uint8_t getPixel(uint16_t x, uint16_t y);
		void clearDisplay();
		void refresh(void);
	private:
		uint8_t _sda, _sclk, _ncs, _ndc, _nrst, _nbusy ;
		void SPI4W_WRITECOM(uint8_t INIT_COM);
		void SPI4W_WRITEDATA(uint8_t INIT_DATA);
		void SPI4W_WRITE(uint8_t INIT_COM,uint8_t INIT_DATA);
		void MYRESET(void);
		void READBUSY(void);
	
}

