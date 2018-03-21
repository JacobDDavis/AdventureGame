
import pexpect
import sys
import time

commands = [["East", "Cave"],
            ["East", "Forest"],
            ["West", "Cave"],
            ["West", "Fort"],
            ["West", "Tunnel"],
            ["North", "Dungeon"],
            ["South", "Tunnel"],
            ["East", "Fort"],
            ["South", "Woods"],
            ["North", "Fort"],
            ["North", "Canopy"],
            ["West", "Dungeon"],
            ["West", "Invalid input"],
            ["quit", "Game Over."]]

child = pexpect.spawnu( './Game' )
child.logfile = sys.stdout

checklist = []

def check_response(dutout, expected):
    print("duot:")
    #print(dutout)
    print(expected[1])
    return(True)

for cmd in commands:
    #print("cmd = {}".format(cmd))
    #time.sleep(2)
    try:
        child.expect('Next move\?', timeout=5)
        child.sendline(cmd[0])
    except:
        print("Exection was thrown expecting {}".format(cmd))
        print(str(child))
        exit()

    try:
        child.expect(cmd[1], timeout = 5)#checks to ensure the game provides proper response
    except:
        print("Error: Unexpected Output")

print("***Test Complete.***")


#for i in checklist:
#print(checklist)
#    if check_response(child.before, cmd):
#        child.sendline(cmd[0])
#    else:
#        print("error in...")
#print(" before Fort {} ".format(child.before))
#print(" after  Fort {}".format(child.after))
#try:
 # child.expect('Game Over\.', timeout=5)
 # child.sendline("quit")

