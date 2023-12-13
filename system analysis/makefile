
CS_ARGS= -r:System.Data.dll -r:mysql-connector-net-8.2.0-noinstall/net8.0/MySql.Data.dll 

run: Program.exe
	mono $<

Program.exe:
	csc Program.cs $(CS_ARGS)


.PHONY:
clean:
	rm -rf *.exe
