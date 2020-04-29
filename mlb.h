typedef struct {
  char *name;
  int wins;
  int loss;
  char *city;
  char *state;
  double payroll;
  double averageSalary;
} Team;

Team * createTeam(char *name, int wins, int loss, char *city, char *state, double payroll, double aveSalary);
Team * readFile(char *fileName);
void printTeam(Team *t); 
void printAllTeams(Team *teams, int size);

void bubbleSortTeams(Team * teams, int size, int (*compar)(const void *, const void *));
void selectionSortTeamsByPayroll(Team * teams, int size);
void selectionSortTeams(Team * teams, int size, int (*compar)(const void *, const void *));
int teamComparison_name(const void *s1, const void *s2);
int teamComparison_winPercentage(const void *s1, const void *s2);
int teamComparison_state(const void *s1, const void *s2);
int teamComparison_stateCity(const void *s1, const void *s2);

int teamComparisonByWinPercentageIncrease(const void *s1, const void *s2);

int teamComparisonByPayrollDesc(const void *s1, const void *s2);
