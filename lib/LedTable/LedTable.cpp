#include "LedTable.h"

struct CharDataStreamTuple {
    char ascii;
    const char* dataStream;
};

static const CharDataStreamTuple gCharDataStreamTable[] = {
    {' ',
    "00000"
    "00000"
    "00000"
    "00000"
    "00000"
    "00000"
    "00000"},
    {'A',
    "01110"
    "10001"
    "10001"
    "10001"
    "11111"
    "10001"
    "10001"},
    {'B',
    "11110"
    "10001"
    "10001"
    "11110"
    "10001"
    "10001"
    "11110"},
    {'C',
    "01110"
    "10001"
    "10000"
    "10000"
    "10000"
    "10001"
    "01110"},
    {'D',
    "11110"
    "10001"
    "10001"
    "10001"
    "10001"
    "10001"
    "11110"},
    {'E',
    "11111"
    "10000"
    "10000"
    "11110"
    "10000"
    "10000"
    "11111"},
    {'F',
    "11111"
    "10000"
    "10000"
    "11110"
    "10000"
    "10000"
    "10000"},
    {'G',
    "01110"
    "10001"
    "10000"
    "10011"
    "10001"
    "10001"
    "01111"},
    {'H',
    "10001"
    "10001"
    "10001"
    "11111"
    "10001"
    "10001"
    "10001"
    },
    {'I',
    "01110"
    "00100"
    "00100"
    "00100"
    "00100"
    "00100"
    "01110"
    },
    {'J',
    "00111"
    "00010"
    "00010"
    "00010"
    "00010"
    "10010"
    "01100"
    },
    {'K',
    "10001"
    "10010"
    "10100"
    "11000"
    "10100"
    "10010"
    "10001"
    },
    {'L',
    "10000"
    "10000"
    "10000"
    "10000"
    "10000"
    "10000"
    "11111"
    },
    {'M',
    "10001"
    "11011"
    "10101"
    "10101"
    "10001"
    "10001"
    "10001"
    },
    {'N',
    "10001"
    "10001"
    "11001"
    "10101"
    "10011"
    "10001"
    "10001"
    },
    {'O',
    "01110"
    "10001"
    "10001"
    "10001"
    "10001"
    "10001"
    "01110"
    },
    {'P',
    "11110"
    "10001"
    "10001"
    "11110"
    "10000"
    "10000"
    "10000"
    },
    {'Q',
    "01110"
    "10001"
    "10001"
    "10001"
    "10101"
    "10010"
    "01101"
    },
    {'R',
    "11110"
    "10001"
    "10001"
    "11110"
    "10100"
    "10010"
    "10001"
    },
    {'S',
    "01110"
    "10001"
    "10000"
    "01110"
    "00001"
    "10001"
    "01110"
    },
    {'T',
    "11111"
    "00100"
    "00100"
    "00100"
    "00100"
    "00100"
    "00100"
    },
    {'U',
    "10001"
    "10001"
    "10001"
    "10001"
    "10001"
    "10001"
    "01110"
    },
    {'V',
    "10001"
    "10001"
    "10001"
    "10001"
    "10001"
    "01010"
    "00100"
    },
    {'W',
    "10001"
    "10001"
    "10001"
    "10101"
    "10101"
    "10101"
    "01010"
    },
    {'X',
    "10001"
    "10001"
    "01010"
    "00100"
    "01010"
    "10001"
    "10001"
    },
    {'Y',
    "10001"
    "10001"
    "10001"
    "01010"
    "00100"
    "00100"
    "00100"
    },
    {'Z',
    "11111"
    "00001"
    "00010"
    "00100"
    "01000"
    "10000"
    "11111"
    },
    {'0',
    "01110"
    "10001"
    "10001"
    "10001"
    "10001"
    "10001"
    "01110"
    },
    {'1',
    "00100"
    "01100"
    "00100"
    "00100"
    "00100"
    "00100"
    "01110"
    },
    {'2',
    "01110"
    "10001"
    "00001"
    "00010"
    "00100"
    "01000"
    "11111"
    },
    {'3',
    "11111"
    "00010"
    "00100"
    "00010"
    "00001"
    "10001"
    "01110"
    },
    {'4',
    "00010"
    "00110"
    "01010"
    "10010"
    "11111"
    "00010"
    "00010"
    },
    {'5',
    "11111"
    "10000"
    "11110"
    "00001"
    "00001"
    "10001"
    "01110"
    },
    {'6',
    "00110"
    "01000"
    "10000"
    "11110"
    "10001"
    "10001"
    "01110"
    },
    {'7',
    "11111"
    "10001"
    "00010"
    "00100"
    "01000"
    "01000"
    "01000"
    },
    {'8',
    "01110"
    "10001"
    "10001"
    "01110"
    "10001"
    "10001"
    "01110"
    },
    {'9',
    "01110"
    "10001"
    "10001"
    "01111"
    "00001"
    "00010"
    "01100"
    },
    {':',
    "00000"
    "01100"
    "01100"
    "00000"
    "01100"
    "01100"
    "00000"
    },
    {'.',
    "00000"
    "00000"
    "00000"
    "00000"
    "00000"
    "01100"
    "01100"
    }

};

const char* lookupChar(char ascii) {
    static const unsigned int tableSize = sizeof(gCharDataStreamTable)/sizeof(gCharDataStreamTable[0]);
    for (unsigned int index = 0; index < tableSize; ++index) {
        const CharDataStreamTuple& tuple = gCharDataStreamTable[index];
        if (tuple.ascii == ascii) {
            return tuple.dataStream;
        }
    }

    return 0;
}
