#!/usr/bin/env bash
#
# TestCase, version 1
#   library for testing c++ classes in bash.

##########################
# A Test Case template for
#+xstream project.
# Globals:
#   SRCDIR
#   TARGETTESTDIR
#   TESTNAME
# Arguments:
#   TARGET_PATH
#   TARGET_NAME
# Returns:
#   None

# set the SRCDIR to the files directory
readonly SRCDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

# set calling command
readonly PARENTCMD=$(ps $PPID | tail -n 1 | awk "{print \$6}")

# set the path to the calling directory
readonly TARGETTESTDIR=$1

# set the name of the test case
readonly TESTNAME=$(basename "${TARGETTESTDIR}" .sh)

# link the logging module
#source ${SRCDIR}/Logger.sh $1;
source "${SRCDIR}"/Setup.sh;
source "${SRCDIR}"/Clean.sh;
source "${SRCDIR}"/CleanTest.sh ${TARGETTESTDIR};
source "${SRCDIR}"/Colours.sh;


# TestCase():
#   creates a new test case which checks exit
#+  status and the difference between stdout
#+  and expected
#   RETURN 0 on success, -int on failure
function TestCase {

    # remove the old data
    cleanTest


    # build test directory if DNE
    if ! [ -d "${SRCDIR}/../TestBuild" ]; then
        setup
    fi

    # navigate to test directory
    cd "${SRCDIR}/../TestBuild"

    ./xstream -s < "${TARGETTESTDIR}/${TESTNAME}.in" > "${TARGETTESTDIR}/${TESTNAME}.out"

    TAB=""
    if ! [ "${PARENTCMD}" = "-Xss2m" ]; then
        TAB="\t"
    fi

    if [ $? -lt "0" ]; then
        echo -e "${TAB}${Black}${TESTNAME}: ${Red}FAILED${NC}"
        pass=1
    else
        echo -e "${TAB}${Black}${TESTNAME}: ${Green}PASSED""${NC}"
        pass=0
    fi

    cp ${SRCDIR}/../TestBuild/data ${TARGETTESTDIR}/data -R
    cd ${SRCDIR}

    return ${pass}
}



