#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>

#include <Zydis/Zydis.h>

#undef NDEBUG
#include <assert.h>

int
main ()
{
  ZyanU8 data[] = {0x51, 0x8D, 0x45, 0xFF, 0x50, 0xFF, 0x75, 0x0C, 0xFF,
                   0x75, 0x08, 0xFF, 0x15, 0xA0, 0xA5, 0x48, 0x76, 0x85,
                   0xC0, 0x0F, 0x88, 0xFC, 0xDA, 0x02, 0x00};

  // The runtime address (instruction pointer) was chosen arbitrarily here in
  // order to better visualize relative addressing.
  //
  ZyanU64 runtime_address = 0x007FFFFFFF400000;

  // Loop over the instructions in our buffer.
  //
  ZyanU8 i = 0;
  ZyanUSize offset = 0;
  ZydisDisassembledInstruction instruction;

  // Expected decoded instructions. (Intel syntax).
  //
  const char* ex [] =
    {
      "push rcx",
      "lea eax, [rbp-0x01]",
      "push rax",
      "push [rbp+0x0C]",
      "push [rbp+0x08]",
      "call [0x008000007588A5B1]",
      "test eax, eax",
      "js 0x007FFFFFFF42DB15",
    };

  while (ZYAN_SUCCESS (ZydisDisassembleIntel (
          /* machine_mode:    */ ZYDIS_MACHINE_MODE_LONG_64,
          /* runtime_address: */ runtime_address,
          /* buffer:          */ data + offset,
          /* length:          */ sizeof (data) - offset,
          /* instruction:     */ &instruction)))
    {
      printf ("%016" PRIX64 "  %s\n", runtime_address, instruction.text);
      assert (strcmp (instruction.text, ex[i]) == 0);

      i++;
      offset += instruction.info.length;
      runtime_address += instruction.info.length;
    }

  return 0;
}
