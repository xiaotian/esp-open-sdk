#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"

static int cur_pin = 0;
static int pins[] = {BIT12, BIT13, BIT15};
static volatile os_timer_t some_timer;

void some_timerfunc(void *arg)
{
  //Do blinky stuff
  int bit = pins[cur_pin];
  if (GPIO_REG_READ(GPIO_OUT_ADDRESS) & bit)
  {
    // set gpio low
    gpio_output_set(0, bit, 0, 0);
  }
  else
  {
    // set gpio high
    cur_pin = ++cur_pin % 3;
    bit = pins[cur_pin];
    gpio_output_set(bit, 0, 0, 0);
  }
}

void ICACHE_FLASH_ATTR user_init()
{
  // init gpio sussytem
  gpio_init();

  // configure UART TXD to be GPIO1, set as output
  PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, FUNC_GPIO12);
  PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, FUNC_GPIO13);
  PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, FUNC_GPIO15);
  //PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO15_U, FUNC_GPIO15); 
  gpio_output_set(0, BIT12, BIT12, 0);
  gpio_output_set(0, BIT13, BIT13, 0);
  gpio_output_set(0, BIT15, BIT15, 0);

  // setup timer (500ms, repeating)
  os_timer_setfn(&some_timer, (os_timer_func_t *)some_timerfunc, NULL);
  os_timer_arm(&some_timer, 1000, 1);
}
