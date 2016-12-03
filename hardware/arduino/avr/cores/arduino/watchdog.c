#include <Arduino.h>

#define RESET_VECTOR ((void(*)()) 0)
#define DEFAULT_TIMEOUT 5000
#define DEFAULT_ONTIMEOUT RESET_VECTOR

static volatile uint16_t ticks = DEFAULT_TIMEOUT;
static volatile uint16_t timeout = DEFAULT_TIMEOUT;
static void (*onTimeout)() = DEFAULT_ONTIMEOUT;

void watchdogTimeout(uint16_t ms)
{
  noInterrupts();
  timeout = ms;
  ticks = ms;
  interrupts();
}

void watchdogOnTimeout(void (*function)())
{
  noInterrupts();
  onTimeout = function;
  interrupts();
}

void watchdogReset()
{
  noInterrupts();
  ticks = timeout;
  interrupts();
}

void watchdogTick()
{
  if (--ticks) return;
  onTimeout();
  RESET_VECTOR();
}
