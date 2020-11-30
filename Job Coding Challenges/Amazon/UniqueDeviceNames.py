def getUniqueDeviceNames(num, deviceNames):
    # creact dict/map to record unique names and number of occurences
    namesDict = {}
    # iterate over names 
    for i, name in enumerate(deviceNames):
        # if name was alread used add a number to the name
        if name in namesDict:
            tempName = name
            deviceNames[i] += str(namesDict[name])
            namesDict[tempName] += 1
        else:
            namesDict[name] = 1
    return deviceNames

print(getUniqueDeviceNames( 6, ["switch", "tv", "switch", "tv","switch", "tv"]))
        