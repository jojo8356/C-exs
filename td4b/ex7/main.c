int equalTabs(int *tab1, int *tab2) {
  for (int i = 0; i < 10; i++) {
    if (tab1[i] != tab2[i]) return 0;
  }
  return 1;
}