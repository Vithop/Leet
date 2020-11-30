import json
myDict = {   
  "id": "04",   
  "name": "sunil",   
  "depatment": "HR",
  "widget":{
    "weather":{
        "temp": "24C"
    }
  }
}  
jsonObj = json.dumps(myDict, indent=4)
print(jsonObj)
print(myDict["widget"])