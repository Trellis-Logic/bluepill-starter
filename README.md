# bluepill-starter
Starter repository for STM32 bluepill projects, using the [STM32 CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) Makefile builder and [stm32-for-vscode](https://marketplace.visualstudio.com/items?itemName=bmd.stm32-for-vscode) and [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug) extension.

This project also supports target emulation with [Renode](https://renode.io/).

## Debug in Renode

From a renode command prompt, use
```
set bin @<path to working directory>/bluepill-starter/build/bluepill-starter.elf
s @scripts/single-node/stm32f103.resc
machine StartGdbServer 3333
```

Then add this launch configuration to Visual Studio Code:
```
        {
            "showDevDebugOutput": true,
            "cwd": "${workspaceRoot}",
            "executable": "./build/bluepill-starter.elf",
            "name": "Debug Renode",
            "request": "launch",
            "type": "cortex-debug",
            "servertype": "external",
            "preLaunchTask": "Build STM",
            "gdbTarget": "localhost:3333",
            "svdFile": "./STM32F103.svd",
        }
 ```




