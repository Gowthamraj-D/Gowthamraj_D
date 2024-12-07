int findLUSlength(char *a, char *b)
{
  return strstr(a, b) && strstr(b, a) ? -1 : fmax(strlen(a), strlen(b));
}
