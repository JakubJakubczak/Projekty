import math

def CalculateSolutions(parts):
    solutions = []
    a = float(parts[0])
    b = float(parts[1])
    print(str(a))
    print(str(b))
    print(str(c))

    delta = b**2 -4*a*c
    print(str(delta))

    if delta < 0:
        return solutions
    if delta == 0:
        x0 = (-b)/(2*a)
        solutions.append(x0)
        return solutions

    else:
        x1 = (-b-math.sqrt(delta))/(2*a)
        x2 = (-b+math.sqrt(delta))/(2*a)
        solutions.append(x1)
        solutions.append(x2)
        return solutions


QuadraticNumbers = input("Enter your quadratic numbers separated by space: ")
parts = QuadraticNumbers.split()
solutions = CalculateSolutions(parts)

if solutions == []:
    print("No solutions")
else:
    print("The solutions are/is "+str(solutions))
    c = float(parts[2])

