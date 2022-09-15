a = int(input())
box_5kg = int(a/5)
while (a-5*box_5kg) % 3 != 0:
    box_5kg -= 1
if box_5kg < 0:
    print(-1)
else:
    print(box_5kg + int((a-box_5kg*5)/3))
