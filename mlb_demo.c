#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

#include "mlb.h"

extern int NUM_TEAMS;

int main(int argc, char **argv) {
  char filePath[] = "data/mlb_nl_2011.txt";

  Team *teams = readFile(filePath);

  printf("Teams, original order: \n");
  printAllTeams(teams, NUM_TEAMS);

  printf("(Bubble) Sorted by win percentage: \n");
  bubbleSortTeams(teams, NUM_TEAMS, teamComparison_winPercentage);
  printAllTeams(teams, NUM_TEAMS);

  printf("(Selection) Sorted by payroll: \n");
  selectionSortTeamsByPayroll(teams, NUM_TEAMS);
  printAllTeams(teams, NUM_TEAMS);

  printf("(Selection with comparator) Sorted by payroll: \n");

  // TODO: change this line to use your comparator for payroll in decreasing
  // order
  selectionSortTeams(teams, NUM_TEAMS, teamComparisonByPayrollDesc);
  printAllTeams(teams, NUM_TEAMS);

  printf("(Quick) Sorted by name: \n");
  qsort(teams, 16, sizeof(Team), teamComparison_name);
  printAllTeams(teams, NUM_TEAMS);

  printf("(Quick) Sorted by win percentage: \n");
  qsort(teams, 16, sizeof(Team), teamComparison_winPercentage);
  printAllTeams(teams, NUM_TEAMS);

  printf("(Quick) Sorted by state (then city): \n");
  qsort(teams, 16, sizeof(Team), teamComparison_stateCity);
  printAllTeams(teams, NUM_TEAMS);

  printf("(Quick) Sorted by win percentage, increasing: \n");
  qsort(teams, 16, sizeof(Team), teamComparisonByWinPercentageIncrease);
  printAllTeams(teams, NUM_TEAMS);

  /* search, find */
  Team *caKey = createTeam("", 0, 0, "", "CA", 0, 0);
  Team *caTeam = NULL;

  qsort(teams, 16, sizeof(Team), teamComparison_winPercentage);
  caTeam = bsearch(caKey, teams, NUM_TEAMS, sizeof(Team), teamComparison_state);
  printf("Search #1 result for CA team (via state): \n");
  printTeam(caTeam);

  qsort(teams, 16, sizeof(Team), teamComparison_state);
  caTeam = bsearch(caKey, teams, NUM_TEAMS, sizeof(Team), teamComparison_state);
  printf("Search #2 result for CA team (via state): \n");
  printTeam(caTeam);

  qsort(teams, 16, sizeof(Team), teamComparison_stateCity);
  caTeam = bsearch(caKey, teams, NUM_TEAMS, sizeof(Team), teamComparison_state);
  printf("Search #3 result for CA team (via state): \n");
  printTeam(caTeam);

  qsort(teams, 16, sizeof(Team), teamComparison_winPercentage);
  size_t elems = 16;
  caTeam = lfind(caKey, teams, &elems, sizeof(Team), teamComparison_state);
  printf("Search #1B result for CA team (via state): \n");
  printTeam(caTeam);

  // TODO: Finish Activity 4 here
  Team *cubKey = createTeam("Cubs", 0, 0, "", "", 0, 0);
  Team *cubTeam = NULL;
  qsort(teams, 16, sizeof(Team), teamComparison_name);
  cubTeam = bsearch(cubKey, teams, NUM_TEAMS, sizeof(Team), teamComparison_name);
  printf("Search #1 result for Cub team (via state): \n");
  printTeam(cubTeam);

  return 0;
}
