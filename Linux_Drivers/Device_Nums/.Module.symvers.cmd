cmd_/home/pardeep/_GIT/RaspberryPi3/Linux_Drivers/Device_NumsFiles/Module.symvers :=  sed 's/ko$$/o/'  /home/pardeep/_GIT/RaspberryPi3/Linux_Drivers/Device_NumsFiles/modules.order | scripts/mod/modpost -m -a    -o /home/pardeep/_GIT/RaspberryPi3/Linux_Drivers/Device_NumsFiles/Module.symvers -e -i Module.symvers -T - 