// The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

// The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

// If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
// Otherwise, they will leave it and go to the queue's end.
// This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

// You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

#include <stdio.h>
int *leave(int *data, int count)
{
  for (int i = 1; i < count; i++)
  {
    data[i - 1] = data[i];
  }
  return data;
}

int *studentGoBack(int *students, int studentSize)
{
  int temp = students[0];
  for (int i = 1; i < studentSize; i++)
  {
    students[i - 1] = students[i];
  }
  students[studentSize - 1] = temp;
  return students;
}

int countStudents(int *students, int studentsSize, int *sandwiches, int sandwichesSize)
{
  while (1)
  {
    if (sandwiches[0] == students[0])
    {
      students = leave(students, studentsSize);
      sandwiches = leave(sandwiches, sandwichesSize);
      studentsSize--;
      sandwichesSize--;
    }
    else
    {
      students = studentGoBack(students, studentsSize);
    }

    int sum = 0;
    for (int i = 0; i < studentsSize; i++)
    {
      sum += students[i];
    }
    if ((sum == studentsSize && sandwiches[0] == 0) || (sum == 0 && sandwiches[0] == 1)) //학생들이 아무리 돌아도 샌드위치를 못 먹을때
      break;
  }

  return studentsSize;
}

void main()
{
  return;
}