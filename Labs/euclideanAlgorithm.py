def extendedEuclideanAlgorithm(r1,r2):
    q = [0,0]
    r = []
    s = [1,0]
    t = [0,1]
    r.append(r1)
    r.append(r2)
    print(" q  |  r  |  s  |  t ")
    print("=====================")
    for i in range(2):
        print(" "+str(q[i])+"  |  "+str(r[i])+"  |  "+str(s[i])+"  |  "+str(t[i]))
    index = 2
    while True:
        q.append(r[index-2]//r[index-1])
        r.append(r[index-2] - q[index]*r[index-1])
        s.append(s[index-2]-q[index]*s[index-1])
        t.append(t[index-2]-q[index]*t[index-1])
        print(" " + str(q[index]) + "  |  " + str(r[index]) + "  |  " + str(s[index]) + "  |  " + str(t[index]))
        if r[index] == 0:
            print("s*a  +  t*b = gcd")
            print(str(s[index-1]) + " * " + str(r[0]) + " + "+str(t[index-1])+ " * " +str(r[1]) + " = "+str(r[index-1]))
            break
        index += 1
 
a = int(input("Podaj pierwszą liczbę: "))
b = int(input("Podaj drugą liczbę: "))
extendedEuclideanAlgorithm(a, b)