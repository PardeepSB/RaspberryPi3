cmd_/home/pardeep/_GIT/RaspberryPi3/Linux_Drivers/Module.symvers :=  sed 's/ko$$/o/'  /home/pardeep/_GIT/RaspberryPi3/Linux_Drivers/modules.order | scripts/mod/modpost -m -a    -o /home/pardeep/_GIT/RaspberryPi3/Linux_Drivers/Module.symvers -e -i Module.symvers -T - 