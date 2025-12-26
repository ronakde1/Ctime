numeral = "XIX"
arr = []
def tonum(val: chr) -> int:
    match val:
        case "I": 
            return 1
        case "V":
            return 5
        case "X":
            return 10
        
n = len(numeral)
for i in range(n):
    arr.append(tonum(numeral[i]))

val = 0
for i in range(0,n-1):
    if arr[i] < arr[i+1]:
        val -= arr[i]
    else:
        val+= arr[i]
val += arr[-1]
print(arr)
print(val)