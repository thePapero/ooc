/*
 * errors.h
 *
 * Definisce la lista dei possibili errori del sistema.
 *
 *  Created on: 05 lug 2019
 *      Author: Antonio De Meis
 */

#ifndef HEADERS_ERRORS_H_
#define HEADERS_ERRORS_H_

#define HES_E_OK                                0

#define HES_E_LEG_CAN_TIMEOUT                   350U
#define HES_E_REMOTE_CAN_TIMEOUT                360U

#define HES_E_DISPLAY_CAN_TIMEOUT               370U

#define HES_E_INCLINOMETRO_CAN_TIMEOUT          380U

#define HES_E_EEPROM_MAILBOX_FULL               390U
#define HES_E_EEPROM_CHECKSUM_FAIL              391U

#define HES_E_DEBUG_TASK_ERROR                  400U

/** Fino a 0x14B (331 decimale) sono usati da IO_ErrorType */
typedef int HES_ErrorType;

/*
 *IO_E_OK   0U
 *IO_E_BUSY   2U
 *IO_E_UNKNOWN   3U
 *IO_E_DRV_SAFETY_CONF_NOT_CONFIG   5U
 *IO_E_INVALID_SAFETY_CONFIG   6U
 *IO_E_DRV_SAFETY_CYCLE_RUNNING   7U
 *IO_E_OPEN_LOAD   10U
 *IO_E_SHORT_GND   11U
 *IO_E_SHORT_BAT   12U
 *IO_E_OPEN_LOAD_OR_SHORT_BAT   13U
 *IO_E_INVALID_VOLTAGE   14U
 *IO_E_NO_DIAG   15U
 *IO_E_PWM_NO_DIAG   IO_E_NO_DIAG
 *IO_E_STARTUP   16U
 *IO_E_SAFE_STATE   17U
 *IO_E_REFERENCE   18U
 *IO_E_SAFETY_SWITCH_DISABLED   19U
 *IO_E_FET_PROT_ACTIVE   20U
 *IO_E_FET_PROT_PERMANENT   21U
 *IO_E_FET_PROT_REENABLE   22U
 *IO_E_FET_PROT_WAIT   23U
 *IO_E_FET_PROT_NOT_ACTIVE   24U
 *IO_E_RESOLVING   25U
 *IO_E_RESOLVING_FAILED   26U
 *IO_E_NULL_POINTER   30U
 *IO_E_INVALID_PARAMETER   31U
 *IO_E_CHANNEL_BUSY   32U
 *IO_E_CHANNEL_NOT_CONFIGURED   33U
 *IO_E_INVALID_CHANNEL_ID   34U
 *IO_E_INVALID_LIMITS   35U
 *IO_E_PERIODIC_NOT_CONFIGURED   36U
 *IO_E_CH_CAPABILITY   37U
 *IO_E_DRIVER_NOT_INITIALIZED   38U
 *IO_E_INVALID_OPERATION   39U
 *IO_E_CAN_OVERFLOW   40U
 *IO_E_CAN_WRONG_HANDLE   41U
 *IO_E_CAN_MAX_MO_REACHED   42U
 *IO_E_CAN_MAX_HANDLES_REACHED   43U
 *IO_E_CAN_FIFO_FULL   44U
 *IO_E_CAN_OLD_DATA   45U
 *IO_E_CAN_ERROR_PASSIVE   46U
 *IO_E_CAN_BUS_OFF   47U
 *IO_E_CAN_ERROR_WARNING   48U
 *IO_E_CAN_TIMEOUT   49U
 *IO_E_EEPROM_RANGE   60U
 *IO_E_UART_BUFFER_FULL   70U
 *IO_E_UART_BUFFER_EMPTY   71U
 *IO_E_UART_OVERFLOW   72U
 *IO_E_UART_PARITY   73U
 *IO_E_UART_FRAMING   74U
 *IO_E_PWD_NOT_FINISHED   101U
 *IO_E_PWD_OVERFLOW   102U
 *IO_E_PWD_CURRENT_THRESH_HIGH   104U
 *IO_E_PWD_CURRENT_THRESH_LOW   105U
 *IO_E_CM_CALIBRATION   146U
 *IO_E_FPGA_NOT_INITIALIZED   200U
 *IO_E_FPGA_TIMEOUT   201U
 *IO_E_FPGA_CRC_ERROR   202U
 *IO_E_FPGA_VERSION   203U
 *IO_E_WD_RANGE   240U
 *IO_E_WD_INITIALIZATION   241U
 *IO_E_WD_PRECISION   242U
 *IO_E_WD_ACTIVATION   243U
 *IO_E_WD_TRIGGER   244U
 *IO_E_WD_SAFE_LOCK   245U
 *IO_E_WD_DEBUGGING_PREPARED   246U
 *IO_E_WD_SELF_MONITORING   247U
 *IO_E_WD_VICE_VERSA_MONITORING   248U
 *IO_E_WD_STATUS_INVALID   249U
 *IO_E_RTC_CLOCK_INTEGRITY_FAILED   250U
 *IO_E_LIN_BIT   260U
 *IO_E_LIN_PHYSICAL_BUS   261U
 *IO_E_LIN_CHECKSUM   262U
 *IO_E_LIN_INCONSISTENT_SYNCH_FIELD   263U
 *IO_E_LIN_NO_RESPONSE   264U
 *IO_E_LIN_FRAMING   265U
 *IO_E_LIN_OVERRUN   266U
 *IO_E_LIN_PARITY   267U
 *IO_E_LIN_TIMEOUT   268U
 *IO_E_FLASH_WRONG_DEVICE_ID   269U
 *IO_E_FLASH_BLANK_CHECK_FAILED   270U
 *IO_E_FLASH_OP_FAILED   271U
 *IO_E_FLASH_OP_TIMEOUT   272U
 *IO_E_INVALID_VARIANT   282U
 *IO_E_INVALID_PROD_DATA   283U
 *IO_E_INVALID_PIN_CONFIG   284U
 *IO_E_INVALID_SERIAL_NUMBER   285U
 *IO_E_CORE_TEST_FAILED   286U
 *IO_E_ERROR_PIN_TEST_TIMEOUT   287U
 *IO_E_ERROR_PIN_TEST_FAILED   288U
 *IO_E_INTERNAL_MEM_FAILED   289U
 *IO_E_INVALID_ESM_INIT_STATUS   290U
 *IO_E_INTERNAL_CSM   292U
 *IO_E_ETH_INIT_FAIL   300U
 *IO_E_ETH_INIT_TIMEOUT   301U
 *IO_E_ETH_DEINIT_TIMEOUT   302U
 *IO_E_ETH_MAC_INVALID   303U
 *IO_E_ETH_READ_FAIL   304U
 *IO_E_ETH_WRITE_FAIL   305U
 *IO_E_ETH_NO_LINK   306U
 *IO_E_ETH_MDIO_TIMEOUT   307U
 *IO_E_ETH_MDIO_READ   308U
 *IO_E_DOWNLOAD_NO_REQ   310U
 *IO_E_DOWNLOAD_TIMEOUT   311U
 *IO_E_DOWNLOAD_HANDSHAKE   312U
 *IO_E_SHM_INTEGRITY   320U
 *IO_E_MPU_REGION_ENABLED   330U
 *IO_E_MPU_REGION_DISABLED   331U
 */

#endif /* HEADERS_ERRORS_H_ */