import random

def main():
    people = []
    groupnumber = 0
    peoplecount = 0
    with open("randomgroupgenpeople.txt", "r") as file:
        for line in file:
            people.append(line.rstrip())
            peoplecount += 1
    while (groupnumber < 1 or groupnumber > peoplecount):
        groupnumber = int(input("Enter number of groups: "))
    peopleingroup = []
    smallestgroup = peoplecount // groupnumber
    for i in range(groupnumber):
        if i < peoplecount % groupnumber:
            peopleingroup.append(smallestgroup + 1)
        else:
            peopleingroup.append(smallestgroup)
    # create a 2D array, where the rows contain groupnumber - 1 lists of people.
    groups = [["placehold" for x in range(peoplecount // groupnumber)] for y in range(groupnumber - 1)]
    for i in range(groupnumber - 1): #remember, there are only groupnumber - 1 rows.
        # if the group is large, add another place.
        if peopleingroup[i] > smallestgroup:
                groups[i].append("placehold")

        for j in range(peopleingroup[i]):
            person = random.choice(people)
            groups[i][j] = person
            people.remove(person)

    for i in range(groupnumber - 1):
        print(f"Group {i + 1}: {groups[i]}")
    print(f"Group {groupnumber}: {people}")
main()
