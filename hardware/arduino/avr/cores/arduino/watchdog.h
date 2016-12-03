#ifndef watchdog_h
#define watchdog_h

#ifdef __cplusplus
extern "C"{
#endif

void watchdogTimeout(uint16_t ms);
void watchdogOnTimeout(void (*function)());
void watchdogReset();
void watchdogTick();

#ifdef __cplusplus
} // extern "C"
#endif
#endif
