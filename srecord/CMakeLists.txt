
INCLUDE (CheckIncludeFiles)
include(CheckFunctionExists)
include(CheckCSourceCompiles)

CHECK_INCLUDE_FILES (inttypes.h HAVE_INTTYPES_H)
CHECK_INCLUDE_FILES (memory.h HAVE_MEMORY_H)

CHECK_INCLUDE_FILES (stdint.h HAVE_STDINT_H)
CHECK_INCLUDE_FILES (stdlib.h HAVE_STDLIB_H)
CHECK_INCLUDE_FILES (strings.h HAVE_STRINGS_H)

CHECK_INCLUDE_FILES (string.h HAVE_STRING_H)
CHECK_INCLUDE_FILES (sys/stat.h HAVE_SYS_STAT_H)
CHECK_INCLUDE_FILES (sys/types.h HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILES (unistd.h HAVE_UNISTD_H)

check_function_exists(snprintf HAVE_SNPRINTF)
check_function_exists(vsnprintf HAVE_VSNPRINTF)

check_c_source_compiles( 
"#include <unistd.h>
int
main ()
{
fpathconf(0, _PC_MIN_HOLE_SIZE);
lseek(0, 0L, SEEK_DATA); lseek(0, 0L, SEEK_HOLE);
  ;
  return 0;
}" HAVE_SPARSE_LSEEK)


set(GEN_DIR ${CMAKE_CURRENT_BINARY_DIR})

configure_file(config.h.cmake.in ${GEN_DIR}/srecord/config.h)


set(SRECORD_SOURCES
./input.cc
./versn_stamp.cc
./vsnprintf.cc
./arglex.cc
./endian.cc
./r250.cc
./pretty_size.cc
./output/filter.cc
./output/file/tektronix_extended.cc
./output/file/formatted_binary.cc
./output/file/binary.cc
./output/file/ti_txt.cc
./output/file/ppb.cc
./output/file/trs80.cc
./output/file/fairchild.cc
./output/file/ppx.cc
./output/file/mips_flash.cc
./output/file/mif.cc
./output/file/intel.cc
./output/file/vmem.cc
./output/file/hexdump.cc
./output/file/c.cc
./output/file/atmel_generic.cc
./output/file/ascii_hex.cc
./output/file/ti_tagged_16.cc
./output/file/signetics.cc
./output/file/idt.cc
./output/file/wilson.cc
./output/file/intel16.cc
./output/file/logisim.cc
./output/file/dec_binary.cc
./output/file/basic.cc
./output/file/ti_tagged.cc
./output/file/fastload.cc
./output/file/spectrum.cc
./output/file/tektronix.cc
./output/file/emon52.cc
./output/file/mos_tech.cc
./output/file/coe.cc
./output/file/brecord.cc
./output/file/aomf.cc
./output/file/four_packed_code.cc
./output/file/mem.cc
./output/file/forth.cc
./output/file/msbin.cc
./output/file/vhdl.cc
./output/file/line_termination.cc
./output/file/cosmac.cc
./output/file/motorola.cc
./output/file/os65v.cc
./output/file/spasm.cc
./output/file/stewie.cc
./output/file/asm.cc
./output/file/needham.cc
./output/file.cc
./output/filter/reblock.cc
./record.cc
./output.cc
./fletcher16.cc
./endian/decode_word.cc
./string/quote_c.cc
./string/url_decode.cc
./string/url_encode.cc
./progname.cc
./quit/normal.cc
./quit/exception.cc
./quit/prefix.cc
./adler16.cc
./defcon.cc
./input/filter.cc
./input/file/tektronix_extended.cc
./input/file/formatted_binary.cc
./input/file/guess.cc
./input/file/binary.cc
./input/file/ti_txt.cc
./input/file/ppb.cc
./input/file/trs80.cc
./input/file/fairchild.cc
./input/file/ppx.cc
./input/file/mips_flash.cc
./input/file/mif.cc
./input/file/intel.cc
./input/file/vmem.cc
./input/file/hexdump.cc
./input/file/atmel_generic.cc
./input/file/ascii_hex.cc
./input/file/ti_tagged_16.cc
./input/file/signetics.cc
./input/file/idt.cc
./input/file/wilson.cc
./input/file/intel16.cc
./input/file/logisim.cc
./input/file/dec_binary.cc
./input/file/ti_tagged.cc
./input/file/fastload.cc
./input/file/spectrum.cc
./input/file/tektronix.cc
./input/file/emon52.cc
./input/file/mos_tech.cc
./input/file/brecord.cc
./input/file/aomf.cc
./input/file/four_packed_code.cc
./input/file/msbin.cc
./input/file/cosmac.cc
./input/file/motorola.cc
./input/file/os65v.cc
./input/file/spasm.cc
./input/file/stewie.cc
./input/file/needham.cc
./input/catenate.cc
./input/interval.cc
./input/file.cc
./input/generator.cc
./input/generator/repeat.cc
./input/generator/random.cc
./input/generator/constant.cc
./input/filter/split.cc
./input/filter/not.cc
./input/filter/offset.cc
./input/filter/unfill.cc
./input/filter/unsplit.cc
./input/filter/fill.cc
./input/filter/xor.cc
./input/filter/sequence.cc
./input/filter/message.cc
./input/filter/crop.cc
./input/filter/message/fletcher16.cc
./input/filter/message/adler16.cc
./input/filter/message/crc32.cc
./input/filter/message/gcrypt.cc
./input/filter/message/adler32.cc
./input/filter/message/stm32.cc
./input/filter/message/crc16.cc
./input/filter/message/fletcher32.cc
./input/filter/interval.cc
./input/filter/interval/length.cc
./input/filter/interval/minimum.cc
./input/filter/interval/maximum.cc
./input/filter/random_fill.cc
./input/filter/or.cc
./input/filter/byte_swap.cc
./input/filter/checksum/positive.cc
./input/filter/checksum/bitnot.cc
./input/filter/checksum/negative.cc
./input/filter/and.cc
./input/filter/checksum.cc
./input/filter/bitrev.cc
./interval.cc
./interval/flatten.cc
./interval/coverage.cc
./memory/walker/continuity.cc
./memory/walker/fletcher16.cc
./memory/walker/adler16.cc
./memory/walker/writer.cc
./memory/walker/alignment.cc
./memory/walker/crc32.cc
./memory/walker/gcrypt.cc
./memory/walker/adler32.cc
./memory/walker/stm32.cc
./memory/walker/crc16.cc
./memory/walker/fletcher32.cc
./memory/walker/compare.cc
./memory/walker.cc
./memory/chunk.cc
./crc32.cc
./arglex/tool.cc
./arglex/tool/input.cc
./arglex/tool/get_number.cc
./arglex/tool/output.cc
./arglex/tool/get_interval.cc
./arglex/tool/get_string.cc
./arglex/tool/get_interval_small.cc
./arglex/abbreviate.cc
./arglex/test_ambiguous.cc
./adler32.cc
./stm32.cc
./crc16.cc
./quit.cc
./memory.cc
./fletcher32.cc
./bitrev.cc    
)

add_library(srecord STATIC ${SRECORD_SOURCES})

target_include_directories(srecord PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
    ${GEN_DIR}
)
