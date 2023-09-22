#include<iostream>
using namespace std;

int main()
{
    printf("Hello");
    return 0;
}
void Auto_Switch(Module_Peripherals_PriorityTypeDef modules)
{
      if(Eeprom_Read_Data(Addr_Switch_Internet, Position_1) == modules.Module_One)
      {
        Eeprom_ClearPage(Switch_Internet_Page);
        Eeprom_Write_Data(Addr_Switch_Internet, Position_1, modules.Module_Two, 1000);
        HAL_NVIC_SystemReset();
      }
      else if(Eeprom_Read_Data(Addr_Switch_Internet, Position_1) == modules.Module_Two)
      {
        Eeprom_ClearPage(Switch_Internet_Page);
        Eeprom_Write_Data(Addr_Switch_Internet, Position_1, modules.Module_Three, 1000);
        HAL_NVIC_SystemReset();
      }
      else if(Eeprom_Read_Data(Addr_Switch_Internet, Position_1) == modules.Module_Three)
      {
        Eeprom_ClearPage(Switch_Internet_Page);
        Eeprom_Write_Data(Addr_Switch_Internet, Position_1, modules.Module_One, 1000);
        HAL_NVIC_SystemReset();
      }
}
// I iust add some comment to test
