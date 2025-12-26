
# check that for a given position, the minimum position < maximum position 
# min position: all members are above them that can be which is team_size - higherskill[i]
# max position: all members are below them that can be which is lowerskill[i]
# if number of possible members is greater than the current team size, then continue the loop until this is no longer true 
# return the previous value 
def getOptimalTeamSize(lowerSkill, higherSkill):
    team_size = 1
    n = len(lowerSkill)
    while True:
        count = 0
        for i in range(n):
            
            min_pos = max(0, team_size - higherSkill[i])
            max_pos = min(team_size, lowerSkill[i])
            if min_pos <= max_pos:
                count += 1
        if count >= team_size:
            team_size += 1
        else:
            return team_size
lowerSkill = [0, 2, 2, 0, 1, 3]
higherSkill = [3, 1, 2, 5, 2, 0]
print(getOptimalTeamSize(lowerSkill,higherSkill))