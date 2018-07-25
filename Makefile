# example4/Makefilehuman.o 
CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -MMD -g
OBJECTS=main.o game.o tile.o race.o item.o brick.o pc.o enemy.o gold.o potion.o goldhoard.o potiontype.o shade.o drow.o vampire.o troll.o goblin.o slime.o human.o elf.o orcs.o dwarf.o dragon.o halfling.o merchant.o  
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

#TESTDIR=test
#EXECSDIR=../executables
#EXECGIVEN=${EXEC}
#SUITE=suite.txt

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean

# @ silences output
#test:
#	@cp ${EXECSDIR}/${EXECGIVEN} ${TESTDIR}                
 # copy over given exec
#	@mv ${TESTDIR}/${EXECGIVEN} ${TESTDIR}/sol_${EXECGIVEN} 
# prefix it with sol_
#	@cp ${EXEC} ${TESTDIR}                                  
# copy over your exec
#	@(cd ${TESTDIR}\	
    # go into test directory
#	&& ./produceOutputs ${SUITE} ./sol_${EXECGIVEN}\        
# run produceOutputs
#	&& ./runSuite ${SUITE} ./${EXEC})                       
# run runSuite
#.PHONY: test
