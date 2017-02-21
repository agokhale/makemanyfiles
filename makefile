all:
	cc -o gomakefiles makemanyfiles.c
clean:
	rm -rf gomakefiles gomakefiles.core noncedir*
	rm -rf payload*
test: 
	sleep 1
	sh palette_generator.sh	


