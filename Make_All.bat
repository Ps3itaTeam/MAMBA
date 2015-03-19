@echo off

set PS3DEV=./ps3dev
set PS3SDK=/c/PSDK3v2
set WIN_PS3SDK=C:/PSDK3v2
set PATH=%WIN_PS3SDK%/mingw/msys/1.0/bin;%WIN_PS3SDK%/mingw/bin;%PS3DEV%/ppu/bin;

rem %PATH%;

if exist mamba del mamba\*.lz.bin>nul
if exist mamba rmdir mamba

del *.bin>nul

make clean

make all

if not exist mamba mkdir mamba

if exist mamba_3_55DEX.lz.bin  move  mamba_3_55DEX.lz.bin  mamba\mamba_355D.lz.bin>nul
if exist mamba_3_55.lz.bin     move  mamba_3_55.lz.bin     mamba\mamba_355C.lz.bin>nul
if exist mamba_4_21.lz.bin     move  mamba_4_21.lz.bin     mamba\mamba_421C.lz.bin>nul
if exist mamba_4_21DEX.lz.bin  move  mamba_4_21DEX.lz.bin  mamba\mamba_421D.lz.bin>nul
if exist mamba_4_30DEX.lz.bin  move  mamba_4_30DEX.lz.bin  mamba\mamba_430D.lz.bin>nul
if exist mamba_4_30.lz.bin     move  mamba_4_30.lz.bin     mamba\mamba_430C.lz.bin>nul
if exist mamba_4_31.lz.bin     move  mamba_4_31.lz.bin     mamba\mamba_431C.lz.bin>nul
if exist mamba_4_40.lz.bin     move  mamba_4_40.lz.bin     mamba\mamba_440C.lz.bin>nul
if exist mamba_4_41.lz.bin     move  mamba_4_41.lz.bin     mamba\mamba_441C.lz.bin>nul
if exist mamba_4_41DEX.lz.bin  move  mamba_4_41DEX.lz.bin  mamba\mamba_441D.lz.bin>nul
if exist mamba_4_46.lz.bin     move  mamba_4_46.lz.bin     mamba\mamba_446C.lz.bin>nul
if exist mamba_4_46DEX.lz.bin  move  mamba_4_46DEX.lz.bin  mamba\mamba_446D.lz.bin>nul
if exist mamba_4_50.lz.bin     move  mamba_4_50.lz.bin     mamba\mamba_450C.lz.bin>nul
if exist mamba_4_50DEX.lz.bin  move  mamba_4_50DEX.lz.bin  mamba\mamba_450D.lz.bin>nul
if exist mamba_4_53.lz.bin     move  mamba_4_53.lz.bin     mamba\mamba_453C.lz.bin>nul
if exist mamba_4_53DEX.lz.bin  move  mamba_4_53DEX.lz.bin  mamba\mamba_453D.lz.bin>nul
if exist mamba_4_55.lz.bin     move  mamba_4_55.lz.bin     mamba\mamba_455C.lz.bin>nul
if exist mamba_4_55DEX.lz.bin  move  mamba_4_55DEX.lz.bin  mamba\mamba_455D.lz.bin>nul
if exist mamba_4_60.lz.bin     move  mamba_4_60.lz.bin     mamba\mamba_460C.lz.bin>nul
if exist mamba_4_65.lz.bin     move  mamba_4_65.lz.bin     mamba\mamba_465C.lz.bin>nul
if exist mamba_4_65DEX.lz.bin  move  mamba_4_65DEX.lz.bin  mamba\mamba_465D.lz.bin>nul
if exist mamba_4_66.lz.bin     move  mamba_4_66.lz.bin     mamba\mamba_466C.lz.bin>nul
if exist mamba_4_66DEX.lz.bin  move  mamba_4_66DEX.lz.bin  mamba\mamba_466D.lz.bin>nul
if exist mamba_4_70.lz.bin     move  mamba_4_70.lz.bin     mamba\mamba_470C.lz.bin>nul
if not exist mamba\355 mkdir mamba\355
if exist mamba_3_55DEX.bin  move  mamba_3_55DEX.bin  mamba\355\mamba_D.bin>nul
if exist mamba_3_55.bin     move  mamba_3_55.bin     mamba\355\mamba_C.bin>nul
if not exist mamba\421 mkdir mamba\421
if exist mamba_4_21.bin     move  mamba_4_21.bin     mamba\421\mamba_C.bin>nul
if exist mamba_4_21DEX.bin  move  mamba_4_21DEX.bin  mamba\421\mamba_D.bin>nul
if not exist mamba\430 mkdir mamba\430
if exist mamba_4_30DEX.bin  move  mamba_4_30DEX.bin  mamba\430\mamba_D.bin>nul
if exist mamba_4_30.bin     move  mamba_4_30.bin     mamba\430\mamba_C.bin>nul
if not exist mamba\431 mkdir mamba\431
if exist mamba_4_31.bin     move  mamba_4_31.bin     mamba\431\mamba_C.bin>nul
if not exist mamba\440 mkdir mamba\440
if exist mamba_4_40.bin     move  mamba_4_40.bin     mamba\440\mamba_C.bin>nul
if not exist mamba\441 mkdir mamba\441
if exist mamba_4_41.bin     move  mamba_4_41.bin     mamba\441\mamba_C.bin>nul
if exist mamba_4_41DEX.bin  move  mamba_4_41DEX.bin  mamba\441\mamba_D.bin>nul
if not exist mamba\446 mkdir mamba\446
if exist mamba_4_46.bin     move  mamba_4_46.bin     mamba\446\mamba_C.bin>nul
if exist mamba_4_46DEX.bin  move  mamba_4_46DEX.bin  mamba\446\mamba_D.bin>nul
if not exist mamba\450 mkdir mamba\450
if exist mamba_4_50.bin     move  mamba_4_50.bin     mamba\450\mamba_C.bin>nul
if exist mamba_4_50DEX.bin  move  mamba_4_50DEX.bin  mamba\450\mamba_D.bin>nul
if not exist mamba\453 mkdir mamba\453
if exist mamba_4_53.bin     move  mamba_4_53.bin     mamba\453\mamba_C.bin>nul
if exist mamba_4_53DEX.bin  move  mamba_4_53DEX.bin  mamba\453\mamba_D.bin>nul
if not exist mamba\455 mkdir mamba\455
if exist mamba_4_55.bin     move  mamba_4_55.bin     mamba\455\mamba_C.bin>nul
if exist mamba_4_55DEX.bin  move  mamba_4_55DEX.bin  mamba\455\mamba_D.bin>nul
if not exist mamba\460 mkdir mamba\460
if exist mamba_4_60.bin     move  mamba_4_60.bin     mamba\460\mamba_C.bin>nul
if not exist mamba\465 mkdir mamba\465
if exist mamba_4_65.bin     move  mamba_4_65.bin     mamba\465\mamba_C.bin>nul
if exist mamba_4_65DEX.bin  move  mamba_4_65DEX.bin  mamba\465\mamba_D.bin>nul
if not exist mamba\466 mkdir mamba\466
if exist mamba_4_66.bin     move  mamba_4_66.bin     mamba\466\mamba_C.bin>nul
if exist mamba_4_66DEX.bin  move  mamba_4_66DEX.bin  mamba\466\mamba_D.bin>nul
if not exist mamba\470 mkdir mamba\470
if exist mamba_4_70.bin     move  mamba_4_70.bin     mamba\470\mamba_C.bin>nul
del *.bin>nul

pause
