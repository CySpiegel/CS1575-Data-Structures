
template<typename T>
bool my_is_sorted(T arr[], int size)
{
  bool isSorted = true;

  for (int i = 0; i <= size - 2; i++)
  {
    if (!(arr[i] >= arr[i + 1]))
    {
      isSorted = false;
    }
  }
  return isSorted;
}