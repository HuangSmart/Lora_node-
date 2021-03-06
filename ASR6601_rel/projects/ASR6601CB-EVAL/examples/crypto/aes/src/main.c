#include "tremo_rcc.h"
#include "drv.h"
#include "algorithm.h"
#include "aes.h"

#define AES_BYTELEN 64

// AES user input data
U8 AES_PLAIN[64] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF,
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x89, 0xF8, 0x65,
    0x22, 0x51, 0x3C, 0x05, 0x3D, 0x4A, 0xB3, 0xBE, 0xFD, 0x8D, 0x9E, 0x19, 0xD0, 0x89, 0xF8, 0x65, 0x22, 0x51, 0x3C,
    0x05, 0x3D, 0x4A, 0xB3, 0xBE, 0xFD, 0x8D, 0x9E, 0x19, 0xD0 };

U8 AES_Key[32] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10,
    0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F };

// AES verify data
U8 AES_128_ECB_CIPHER[64] = { 0x69, 0xC4, 0xE0, 0xD8, 0x6A, 0x7B, 0x04, 0x30, 0xD8, 0xCD, 0xB7, 0x80, 0x70, 0xB4, 0xC5,
    0x5A, 0x69, 0xC4, 0xE0, 0xD8, 0x6A, 0x7B, 0x04, 0x30, 0xD8, 0xCD, 0xB7, 0x80, 0x70, 0xB4, 0xC5, 0x5A, 0x4B, 0x8E,
    0x37, 0xE1, 0x55, 0xE7, 0x16, 0x9E, 0x6F, 0x3C, 0xB3, 0x6D, 0xB8, 0xA6, 0x61, 0xDD, 0x4B, 0x8E, 0x37, 0xE1, 0x55,
    0xE7, 0x16, 0x9E, 0x6F, 0x3C, 0xB3, 0x6D, 0xB8, 0xA6, 0x61, 0xDD };

U8 AES_OUT[64];

void aes_ecb(void)
{
    aes_init(AES_Key, 16, 0, NULL);
    aes_crypto(AES_PLAIN, AES_BYTELEN, 0, AES_OUT);
    aes_close();
}

int main(void)
{
    rcc_enable_peripheral_clk(RCC_PERIPHERAL_SAC, true);

    aes_ecb();

    /* Infinite loop */
    while (1) { }

    return 0;
}

#ifdef USE_FULL_ASSERT
void assert_failed(void* file, uint32_t line)
{
    (void)file;
    (void)line;

    while (1) { }
}
#endif
