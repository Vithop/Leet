from collections import defaultdict 

def isValidSubString(s, charMap):
    print(tempS)
    for c in tempS:
        occur_subStr = tempS.count(c)
        if occur_subStr != len(charMap[c]):
            return False
    return True

def findSubstrings(input):
    """
    :type input: str
    :rtype: List[str]
    """                    
    subStr = []
    charMap = defaultdict(list)
    for i, c in enumerate(input):
        charMap[c].append(i)
       
    for k , v in charMap.items():
        num_occ = len(v)

        if num_occ == 1:
            subStr.append(k)
        else:
            tempS = input[v[0]: v[-1]+1]
            
            if isValidSubString(tempS, charMap):
                
                subStr.append(tempS)
    
    return subStr


print(findSubstrings("bbeadcxede"))