#include <stdint.h>
#include <string>

class CRC32
{
public:
  static uint32_t update(uint32_t crc, char *buf, int len)
  {
    static bool flg = false;
    static uint32_t table[256];
    if (!flg)
    {
      int i, j, crc;
      for (i = 0; i < 256; i++)
        for (j = 0, table[i] = i; j < 8; j++)
          table[i] =
              (table[i] >> 1) ^ ((table[i] & 1) ? CRC32::polynomial : 0);
      flg = true;
    }
    crc = ~crc;
    for (int i = 0; i < len; i++)
      crc = (crc >> 8) ^ table[(crc ^ buf[i]) & 0xff];
    return ~crc;
  }

private:
  static const uint32_t polynomial = 0xEDB88320;
};