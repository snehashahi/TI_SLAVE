################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS

GEN_OPTS += /Users/tuddi/workspace_v7/tirtos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug/configPkg/compiler.opt
GEN_OPTS__FLAG := --cmd_file="/Users/tuddi/workspace_v7/tirtos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug/configPkg/compiler.opt"
GEN_CMDS += /Users/tuddi/workspace_v7/tirtos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug/configPkg/linker.cmd
GEN_CMDS__FLAG := -l"/Users/tuddi/workspace_v7/tirtos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug/configPkg/linker.cmd"

ORDERED_OBJS += \
"./CC3220SF_LAUNCHXL.obj" \
"./i2ctmp006.obj" \
"./main_tirtos.obj" \
"../CC3220SF_LAUNCHXL_TIRTOS.cmd" \
$(GEN_CMDS__FLAG) \
-lti/display/lib/display.aem4 \
-lti/grlib/lib/ccs/m4/grlib.a \
-lthird_party/spiffs/lib/ccs/m4/spiffs.a \
-lti/drivers/lib/drivers_cc32xx.aem4 \
-lthird_party/fatfs/lib/ccs/m4/fatfs.a \
-lti/dpl/lib/dpl_cc32xx.aem4 \
-lti/devices/cc32xx/driverlib/ccs/Release/driverlib.a \
-llibc.a \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.out \

EXE_OUTPUTS__QUOTED += \
"i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.out" \

BIN_OUTPUTS += \
i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.bin \

BIN_OUTPUTS__QUOTED += \
"i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.bin" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.out"

dependents:
	-cd /Users/tuddi/workspace_v7/tirtos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug && $(MAKE) all

# Tool invocations
i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS) /Users/tuddi/workspace_v7/tirtos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug/tirtos_builds_CC3220SF_LAUNCHXL_release_ccs.lib
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on -z -m"i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.map" -i"/Applications/ti/simplelink_cc32xx_sdk_2_10_00_04/source" -i"/Applications/ti/simplelink_cc32xx_sdk_2_10_00_04/kernel/tirtos/packages" -i"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/lib" -i"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs_linkInfo.xml" --rom_model -o "i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.bin: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armhex"  -o "i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "CC3220SF_LAUNCHXL.obj" "i2ctmp006.obj" "main_tirtos.obj" 
	-$(RM) "CC3220SF_LAUNCHXL.d" "i2ctmp006.d" "main_tirtos.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-/Applications/ti/ccsv7/utils/tiobj2bin/tiobj2bin i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.out i2ctmp006_CC3220SF_LAUNCHXL_tirtos_ccs.bin /Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armofd /Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armhex /Applications/ti/ccsv7/utils/tiobj2bin/mkhex4bin
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/Users/tuddi/workspace_v7/tirtos_builds_CC3220SF_LAUNCHXL_release_ccs/Debug/tirtos_builds_CC3220SF_LAUNCHXL_release_ccs.lib:

-include ../makefile.targets

