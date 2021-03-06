#ifndef _SSD1289_H
#define _SSD1289_H

#include <Cariad.h>

class SSD1289 : public Cariad {
    private:
        uint8_t pin_rs;
        uint8_t pin_rd;
        uint8_t pin_wr;
        uint8_t pin_cs;
        uint8_t pin_reset;
        uint8_t pin_d0;
        uint8_t pin_d1;
        uint8_t pin_d2;
        uint8_t pin_d3;
        uint8_t pin_d4;
        uint8_t pin_d5;
        uint8_t pin_d6;
        uint8_t pin_d7;
        uint8_t pin_d8;
        uint8_t pin_d9;
        uint8_t pin_d10;
        uint8_t pin_d11;
        uint8_t pin_d12;
        uint8_t pin_d13;
        uint8_t pin_d14;
        uint8_t pin_d15;

        p32_ioport *port_rs;
        p32_ioport *port_rd;
        p32_ioport *port_wr;
        p32_ioport *port_d0;
        p32_ioport *port_d1;
        p32_ioport *port_d2;
        p32_ioport *port_d3;
        p32_ioport *port_d4;
        p32_ioport *port_d5;
        p32_ioport *port_d6;
        p32_ioport *port_d7;
        p32_ioport *port_d8;
        p32_ioport *port_d9;
        p32_ioport *port_d10;
        p32_ioport *port_d11;
        p32_ioport *port_d12;
        p32_ioport *port_d13;
        p32_ioport *port_d14;
        p32_ioport *port_d15;

        uint32_t mask_rs;
        uint32_t mask_rd;
        uint32_t mask_wr;
        uint32_t mask_d0;
        uint32_t mask_d1;
        uint32_t mask_d2;
        uint32_t mask_d3;
        uint32_t mask_d4;
        uint32_t mask_d5;
        uint32_t mask_d6;
        uint32_t mask_d7;
        uint32_t mask_d8;
        uint32_t mask_d9;
        uint32_t mask_d10;
        uint32_t mask_d11;
        uint32_t mask_d12;
        uint32_t mask_d13;
        uint32_t mask_d14;
        uint32_t mask_d15;

	public:
        static const int Width      = 240;
        static const int Height     = 320;

        virtual void command(uint16_t);
        virtual void data(uint16_t);

		SSD1289() {}
        SSD1289(
            uint8_t rs, uint8_t wr, uint8_t rd, uint8_t cs, uint8_t reset,
            uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
            uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7,
            uint8_t d8, uint8_t d9, uint8_t d10, uint8_t d11,
            uint8_t d12, uint8_t d13, uint8_t d14, uint8_t d15
        );


        void startDisplay();

		void setAddrWindow(int x0, int y0, int x1, int y1);
        void fillScreen(color_t color);
        void setPixel(int x, int y, color_t color);
        void drawVerticalLine(int x, int y, int h, color_t color);
        void drawHorizontalLine(int x, int y, int w, color_t color);
        void fillRectangle(int x, int y, int w, int h, color_t color);
        void setRotation(int r);
        void invertDisplay(bool i);
        void displayOn() {} // Not implemented
        void displayOff() {} // Not implemented

        virtual void initializeDevice();
        virtual void openWindow(int x0, int y0, int x1, int y1);
        virtual void windowData(color_t d);
        virtual void windowData(color_t *d, int l);
        virtual void closeWindow();

};


class SSD1289_PMP : public SSD1289 {
    private:

        uint8_t pin_reset;

    public:
        void command(uint16_t);
        void data(uint16_t);

        SSD1289_PMP(uint8_t res) : pin_reset(res) {}

        void initializeDevice();
};


#endif
