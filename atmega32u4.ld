
MEMORY
{
  text (rx) : ORIGIN = 0x0000,   LENGTH = 32K
  data (rw) : ORIGIN = 0x800000, LENGTH =  4K
  bss  (rw) : ORIGIN = 0x804000, LENGTH =  4K
}

SECTIONS
{
  .text :
  {
    *(.text)
  } > text

  .data :
  {
    *(.data)
  } > data

  .bss :
  {
    *(.bss)
  } > bss
}

