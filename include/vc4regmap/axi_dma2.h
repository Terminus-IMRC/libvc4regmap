/*
 * This file is also derived from Brcm_Android_ICS_Graphics_Stack, but thsese
 * changes below are applied:
 * - Fix some *_RESET values written as 0000000000 instead of 0x00000000.
 * - Rewrite register definitions with DMA2_BASE.
 */

#define DMA2_BASE                                                0x007200
#define DMA2_CS                                                  HW_REGISTER_RW( DMA2_BASE+0x00 ) 
   #define DMA2_CS_MASK                                          0xf0ff017f
   #define DMA2_CS_WIDTH                                         32
   #define DMA2_CS_RESET                                         0x00000000
      #define DMA2_CS_RESET_BITS                                 31:31
      #define DMA2_CS_RESET_SET                                  0x80000000
      #define DMA2_CS_RESET_CLR                                  0x7fffffff
      #define DMA2_CS_RESET_MSB                                  31
      #define DMA2_CS_RESET_LSB                                  31
      #define DMA2_CS_ABORT_BITS                                 30:30
      #define DMA2_CS_ABORT_SET                                  0x40000000
      #define DMA2_CS_ABORT_CLR                                  0xbfffffff
      #define DMA2_CS_ABORT_MSB                                  30
      #define DMA2_CS_ABORT_LSB                                  30
      #define DMA2_CS_DISDEBUG_BITS                              29:29
      #define DMA2_CS_DISDEBUG_SET                               0x20000000
      #define DMA2_CS_DISDEBUG_CLR                               0xdfffffff
      #define DMA2_CS_DISDEBUG_MSB                               29
      #define DMA2_CS_DISDEBUG_LSB                               29
      #define DMA2_CS_WAIT_FOR_OUTSTANDING_WRITES_BITS           28:28
      #define DMA2_CS_WAIT_FOR_OUTSTANDING_WRITES_SET            0x10000000
      #define DMA2_CS_WAIT_FOR_OUTSTANDING_WRITES_CLR            0xefffffff
      #define DMA2_CS_WAIT_FOR_OUTSTANDING_WRITES_MSB            28
      #define DMA2_CS_WAIT_FOR_OUTSTANDING_WRITES_LSB            28
      #define DMA2_CS_PANIC_PRIORITY_BITS                        23:20
      #define DMA2_CS_PANIC_PRIORITY_SET                         0x00f00000
      #define DMA2_CS_PANIC_PRIORITY_CLR                         0xff0fffff
      #define DMA2_CS_PANIC_PRIORITY_MSB                         23
      #define DMA2_CS_PANIC_PRIORITY_LSB                         20
      #define DMA2_CS_PRIORITY_BITS                              19:16
      #define DMA2_CS_PRIORITY_SET                               0x000f0000
      #define DMA2_CS_PRIORITY_CLR                               0xfff0ffff
      #define DMA2_CS_PRIORITY_MSB                               19
      #define DMA2_CS_PRIORITY_LSB                               16
      #define DMA2_CS_ERROR_BITS                                 8:8
      #define DMA2_CS_ERROR_SET                                  0x00000100
      #define DMA2_CS_ERROR_CLR                                  0xfffffeff
      #define DMA2_CS_ERROR_MSB                                  8
      #define DMA2_CS_ERROR_LSB                                  8
      #define DMA2_CS_WAITING_FOR_OUTSTANDING_WRITES_BITS        6:6
      #define DMA2_CS_WAITING_FOR_OUTSTANDING_WRITES_SET         0x00000040
      #define DMA2_CS_WAITING_FOR_OUTSTANDING_WRITES_CLR         0xffffffbf
      #define DMA2_CS_WAITING_FOR_OUTSTANDING_WRITES_MSB         6
      #define DMA2_CS_WAITING_FOR_OUTSTANDING_WRITES_LSB         6
      #define DMA2_CS_DREQ_STOPS_DMA_BITS                        5:5
      #define DMA2_CS_DREQ_STOPS_DMA_SET                         0x00000020
      #define DMA2_CS_DREQ_STOPS_DMA_CLR                         0xffffffdf
      #define DMA2_CS_DREQ_STOPS_DMA_MSB                         5
      #define DMA2_CS_DREQ_STOPS_DMA_LSB                         5
      #define DMA2_CS_PAUSED_BITS                                4:4
      #define DMA2_CS_PAUSED_SET                                 0x00000010
      #define DMA2_CS_PAUSED_CLR                                 0xffffffef
      #define DMA2_CS_PAUSED_MSB                                 4
      #define DMA2_CS_PAUSED_LSB                                 4
      #define DMA2_CS_DREQ_BITS                                  3:3
      #define DMA2_CS_DREQ_SET                                   0x00000008
      #define DMA2_CS_DREQ_CLR                                   0xfffffff7
      #define DMA2_CS_DREQ_MSB                                   3
      #define DMA2_CS_DREQ_LSB                                   3
      #define DMA2_CS_INT_BITS                                   2:2
      #define DMA2_CS_INT_SET                                    0x00000004
      #define DMA2_CS_INT_CLR                                    0xfffffffb
      #define DMA2_CS_INT_MSB                                    2
      #define DMA2_CS_INT_LSB                                    2
      #define DMA2_CS_END_BITS                                   1:1
      #define DMA2_CS_END_SET                                    0x00000002
      #define DMA2_CS_END_CLR                                    0xfffffffd
      #define DMA2_CS_END_MSB                                    1
      #define DMA2_CS_END_LSB                                    1
      #define DMA2_CS_ACTIVE_BITS                                0:0
      #define DMA2_CS_ACTIVE_SET                                 0x00000001
      #define DMA2_CS_ACTIVE_CLR                                 0xfffffffe
      #define DMA2_CS_ACTIVE_MSB                                 0
      #define DMA2_CS_ACTIVE_LSB                                 0
#define DMA2_CONBLK_AD                                           HW_REGISTER_RW( DMA2_BASE+0x04 ) 
   #define DMA2_CONBLK_AD_MASK                                   0xffffffe0
   #define DMA2_CONBLK_AD_WIDTH                                  32
   #define DMA2_CONBLK_AD_RESET                                  0x00000000
      #define DMA2_CONBLK_AD_SCB_ADDR_BITS                       31:5
      #define DMA2_CONBLK_AD_SCB_ADDR_SET                        0xffffffe0
      #define DMA2_CONBLK_AD_SCB_ADDR_CLR                        0x0000001f
      #define DMA2_CONBLK_AD_SCB_ADDR_MSB                        31
      #define DMA2_CONBLK_AD_SCB_ADDR_LSB                        5
#define DMA2_TI                                                  HW_REGISTER_RO( DMA2_BASE+0x08 ) 
   #define DMA2_TI_MASK                                          0x07fffffb
   #define DMA2_TI_WIDTH                                         27
      #define DMA2_TI_NO_WIDE_BURSTS_BITS                        26:26
      #define DMA2_TI_NO_WIDE_BURSTS_SET                         0x04000000
      #define DMA2_TI_NO_WIDE_BURSTS_CLR                         0xfbffffff
      #define DMA2_TI_NO_WIDE_BURSTS_MSB                         26
      #define DMA2_TI_NO_WIDE_BURSTS_LSB                         26
      #define DMA2_TI_WAITS_BITS                                 25:21
      #define DMA2_TI_WAITS_SET                                  0x03e00000
      #define DMA2_TI_WAITS_CLR                                  0xfc1fffff
      #define DMA2_TI_WAITS_MSB                                  25
      #define DMA2_TI_WAITS_LSB                                  21
      #define DMA2_TI_PERMAP_BITS                                20:16
      #define DMA2_TI_PERMAP_SET                                 0x001f0000
      #define DMA2_TI_PERMAP_CLR                                 0xffe0ffff
      #define DMA2_TI_PERMAP_MSB                                 20
      #define DMA2_TI_PERMAP_LSB                                 16
      #define DMA2_TI_BURST_LENGTH_BITS                          15:12
      #define DMA2_TI_BURST_LENGTH_SET                           0x0000f000
      #define DMA2_TI_BURST_LENGTH_CLR                           0xffff0fff
      #define DMA2_TI_BURST_LENGTH_MSB                           15
      #define DMA2_TI_BURST_LENGTH_LSB                           12
      #define DMA2_TI_SRC_IGNORE_BITS                            11:11
      #define DMA2_TI_SRC_IGNORE_SET                             0x00000800
      #define DMA2_TI_SRC_IGNORE_CLR                             0xfffff7ff
      #define DMA2_TI_SRC_IGNORE_MSB                             11
      #define DMA2_TI_SRC_IGNORE_LSB                             11
      #define DMA2_TI_SRC_DREQ_BITS                              10:10
      #define DMA2_TI_SRC_DREQ_SET                               0x00000400
      #define DMA2_TI_SRC_DREQ_CLR                               0xfffffbff
      #define DMA2_TI_SRC_DREQ_MSB                               10
      #define DMA2_TI_SRC_DREQ_LSB                               10
      #define DMA2_TI_SRC_WIDTH_BITS                             9:9
      #define DMA2_TI_SRC_WIDTH_SET                              0x00000200
      #define DMA2_TI_SRC_WIDTH_CLR                              0xfffffdff
      #define DMA2_TI_SRC_WIDTH_MSB                              9
      #define DMA2_TI_SRC_WIDTH_LSB                              9
      #define DMA2_TI_SRC_INC_BITS                               8:8
      #define DMA2_TI_SRC_INC_SET                                0x00000100
      #define DMA2_TI_SRC_INC_CLR                                0xfffffeff
      #define DMA2_TI_SRC_INC_MSB                                8
      #define DMA2_TI_SRC_INC_LSB                                8
      #define DMA2_TI_DEST_IGNORE_BITS                           7:7
      #define DMA2_TI_DEST_IGNORE_SET                            0x00000080
      #define DMA2_TI_DEST_IGNORE_CLR                            0xffffff7f
      #define DMA2_TI_DEST_IGNORE_MSB                            7
      #define DMA2_TI_DEST_IGNORE_LSB                            7
      #define DMA2_TI_DEST_DREQ_BITS                             6:6
      #define DMA2_TI_DEST_DREQ_SET                              0x00000040
      #define DMA2_TI_DEST_DREQ_CLR                              0xffffffbf
      #define DMA2_TI_DEST_DREQ_MSB                              6
      #define DMA2_TI_DEST_DREQ_LSB                              6
      #define DMA2_TI_DEST_WIDTH_BITS                            5:5
      #define DMA2_TI_DEST_WIDTH_SET                             0x00000020
      #define DMA2_TI_DEST_WIDTH_CLR                             0xffffffdf
      #define DMA2_TI_DEST_WIDTH_MSB                             5
      #define DMA2_TI_DEST_WIDTH_LSB                             5
      #define DMA2_TI_DEST_INC_BITS                              4:4
      #define DMA2_TI_DEST_INC_SET                               0x00000010
      #define DMA2_TI_DEST_INC_CLR                               0xffffffef
      #define DMA2_TI_DEST_INC_MSB                               4
      #define DMA2_TI_DEST_INC_LSB                               4
      #define DMA2_TI_WAIT_RESP_BITS                             3:3
      #define DMA2_TI_WAIT_RESP_SET                              0x00000008
      #define DMA2_TI_WAIT_RESP_CLR                              0xfffffff7
      #define DMA2_TI_WAIT_RESP_MSB                              3
      #define DMA2_TI_WAIT_RESP_LSB                              3
      #define DMA2_TI_TDMODE_BITS                                1:1
      #define DMA2_TI_TDMODE_SET                                 0x00000002
      #define DMA2_TI_TDMODE_CLR                                 0xfffffffd
      #define DMA2_TI_TDMODE_MSB                                 1
      #define DMA2_TI_TDMODE_LSB                                 1
      #define DMA2_TI_INTEN_BITS                                 0:0
      #define DMA2_TI_INTEN_SET                                  0x00000001
      #define DMA2_TI_INTEN_CLR                                  0xfffffffe
      #define DMA2_TI_INTEN_MSB                                  0
      #define DMA2_TI_INTEN_LSB                                  0
#define DMA2_SOURCE_AD                                           HW_REGISTER_RO( DMA2_BASE+0x0c ) 
   #define DMA2_SOURCE_AD_MASK                                   0xffffffff
   #define DMA2_SOURCE_AD_WIDTH                                  32
      #define DMA2_SOURCE_AD_S_ADDR_BITS                         31:0
      #define DMA2_SOURCE_AD_S_ADDR_SET                          0xffffffff
      #define DMA2_SOURCE_AD_S_ADDR_CLR                          0x00000000
      #define DMA2_SOURCE_AD_S_ADDR_MSB                          31
      #define DMA2_SOURCE_AD_S_ADDR_LSB                          0
#define DMA2_DEST_AD                                             HW_REGISTER_RO( DMA2_BASE+0x10 ) 
   #define DMA2_DEST_AD_MASK                                     0xffffffff
   #define DMA2_DEST_AD_WIDTH                                    32
      #define DMA2_DEST_AD_D_ADDR_BITS                           31:0
      #define DMA2_DEST_AD_D_ADDR_SET                            0xffffffff
      #define DMA2_DEST_AD_D_ADDR_CLR                            0x00000000
      #define DMA2_DEST_AD_D_ADDR_MSB                            31
      #define DMA2_DEST_AD_D_ADDR_LSB                            0
#define DMA2_TXFR_LEN                                            HW_REGISTER_RO( DMA2_BASE+0x14 ) 
   #define DMA2_TXFR_LEN_MASK                                    0x3fffffff
   #define DMA2_TXFR_LEN_WIDTH                                   30
      #define DMA2_TXFR_LEN_YLENGTH_BITS                         29:16
      #define DMA2_TXFR_LEN_YLENGTH_SET                          0x3fff0000
      #define DMA2_TXFR_LEN_YLENGTH_CLR                          0xc000ffff
      #define DMA2_TXFR_LEN_YLENGTH_MSB                          29
      #define DMA2_TXFR_LEN_YLENGTH_LSB                          16
      #define DMA2_TXFR_LEN_XLENGTH_BITS                         15:0
      #define DMA2_TXFR_LEN_XLENGTH_SET                          0x0000ffff
      #define DMA2_TXFR_LEN_XLENGTH_CLR                          0xffff0000
      #define DMA2_TXFR_LEN_XLENGTH_MSB                          15
      #define DMA2_TXFR_LEN_XLENGTH_LSB                          0
#define DMA2_STRIDE                                              HW_REGISTER_RO( DMA2_BASE+0x18 ) 
   #define DMA2_STRIDE_MASK                                      0xffffffff
   #define DMA2_STRIDE_WIDTH                                     32
      #define DMA2_STRIDE_D_STRIDE_BITS                          31:16
      #define DMA2_STRIDE_D_STRIDE_SET                           0xffff0000
      #define DMA2_STRIDE_D_STRIDE_CLR                           0x0000ffff
      #define DMA2_STRIDE_D_STRIDE_MSB                           31
      #define DMA2_STRIDE_D_STRIDE_LSB                           16
      #define DMA2_STRIDE_S_STRIDE_BITS                          15:0
      #define DMA2_STRIDE_S_STRIDE_SET                           0x0000ffff
      #define DMA2_STRIDE_S_STRIDE_CLR                           0xffff0000
      #define DMA2_STRIDE_S_STRIDE_MSB                           15
      #define DMA2_STRIDE_S_STRIDE_LSB                           0
#define DMA2_NEXTCONBK                                           HW_REGISTER_RO( DMA2_BASE+0x1c ) 
   #define DMA2_NEXTCONBK_MASK                                   0xffffffe0
   #define DMA2_NEXTCONBK_WIDTH                                  32
      #define DMA2_NEXTCONBK_ADDR_BITS                           31:5
      #define DMA2_NEXTCONBK_ADDR_SET                            0xffffffe0
      #define DMA2_NEXTCONBK_ADDR_CLR                            0x0000001f
      #define DMA2_NEXTCONBK_ADDR_MSB                            31
      #define DMA2_NEXTCONBK_ADDR_LSB                            5
#define DMA2_DEBUG                                               HW_REGISTER_RW( DMA2_BASE+0x20 ) 
   #define DMA2_DEBUG_MASK                                       0x1ffffff7
   #define DMA2_DEBUG_WIDTH                                      29
   #define DMA2_DEBUG_RESET                                      0x00000000
      #define DMA2_DEBUG_LITE_BITS                               28:28
      #define DMA2_DEBUG_LITE_SET                                0x10000000
      #define DMA2_DEBUG_LITE_CLR                                0xefffffff
      #define DMA2_DEBUG_LITE_MSB                                28
      #define DMA2_DEBUG_LITE_LSB                                28
      #define DMA2_DEBUG_VERSION_BITS                            27:25
      #define DMA2_DEBUG_VERSION_SET                             0x0e000000
      #define DMA2_DEBUG_VERSION_CLR                             0xf1ffffff
      #define DMA2_DEBUG_VERSION_MSB                             27
      #define DMA2_DEBUG_VERSION_LSB                             25
      #define DMA2_DEBUG_DMA_STATE_BITS                          24:16
      #define DMA2_DEBUG_DMA_STATE_SET                           0x01ff0000
      #define DMA2_DEBUG_DMA_STATE_CLR                           0xfe00ffff
      #define DMA2_DEBUG_DMA_STATE_MSB                           24
      #define DMA2_DEBUG_DMA_STATE_LSB                           16
      #define DMA2_DEBUG_DMA_ID_BITS                             15:8
      #define DMA2_DEBUG_DMA_ID_SET                              0x0000ff00
      #define DMA2_DEBUG_DMA_ID_CLR                              0xffff00ff
      #define DMA2_DEBUG_DMA_ID_MSB                              15
      #define DMA2_DEBUG_DMA_ID_LSB                              8
      #define DMA2_DEBUG_OUTSTANDING_WRITES_BITS                 7:4
      #define DMA2_DEBUG_OUTSTANDING_WRITES_SET                  0x000000f0
      #define DMA2_DEBUG_OUTSTANDING_WRITES_CLR                  0xffffff0f
      #define DMA2_DEBUG_OUTSTANDING_WRITES_MSB                  7
      #define DMA2_DEBUG_OUTSTANDING_WRITES_LSB                  4
      #define DMA2_DEBUG_READ_ERROR_BITS                         2:2
      #define DMA2_DEBUG_READ_ERROR_SET                          0x00000004
      #define DMA2_DEBUG_READ_ERROR_CLR                          0xfffffffb
      #define DMA2_DEBUG_READ_ERROR_MSB                          2
      #define DMA2_DEBUG_READ_ERROR_LSB                          2
      #define DMA2_DEBUG_FIFO_ERROR_BITS                         1:1
      #define DMA2_DEBUG_FIFO_ERROR_SET                          0x00000002
      #define DMA2_DEBUG_FIFO_ERROR_CLR                          0xfffffffd
      #define DMA2_DEBUG_FIFO_ERROR_MSB                          1
      #define DMA2_DEBUG_FIFO_ERROR_LSB                          1
      #define DMA2_DEBUG_READ_LAST_NOT_SET_ERROR_BITS            0:0
      #define DMA2_DEBUG_READ_LAST_NOT_SET_ERROR_SET             0x00000001
      #define DMA2_DEBUG_READ_LAST_NOT_SET_ERROR_CLR             0xfffffffe
      #define DMA2_DEBUG_READ_LAST_NOT_SET_ERROR_MSB             0
      #define DMA2_DEBUG_READ_LAST_NOT_SET_ERROR_LSB             0
