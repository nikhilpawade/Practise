#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct st {
	int enable;
	char start_time[12];
	char stop_time[12];
	struct st *next;
};

static int get_diff_time(char *time, char *time1)
{

	char *t1, *t2, *s1, *s2, *token, *token1;
        t1 = strdup(time);
        t2 = strdup(time1);

        token = strtok_r(t1, ":", &s1);
        token1 = strtok_r(t2, ":", &s2);
        while (token && token1) {
                if (atoi(token) > atoi(token1)) {
                        printf("AP time base scan : Timer 1 value is greater than Timer2");
                        free(t1);
                        free(t2);
                        return 1;
                } else if (atoi(token) < atoi(token1) ) {
                        printf("AP time base scan : Timer 2 value is greater than Timer1");
                        free(t1);
                        free(t2);
                        return 2;
                }
                token = strtok_r(NULL, ":", &s1);
                token1 = strtok_r(NULL, ":", &s2);
        }

	printf("AP time base scan : Both timer value is same");
        free(t1);
        free(t2);
        return 0;
}

static int add_sort( struct st **ptr, char *start_time, char *stop_time) 
{
	int diff_starttime, diff_stoptime, diff_stop_start_time, diff_start_stop_time, diff_next_start_time;
	struct st *tmp, *tmp1;
	printf("NIKHIL---------> %s %s\n",start_time,stop_time);

	if( *ptr != NULL) {
		diff_starttime = get_diff_time((*ptr)->start_time, start_time);
	}
	if( *ptr == NULL || diff_starttime == 1) {
		/* Timer add first time */
		printf("\nTEST----NULL\n");
		tmp = malloc(sizeof(struct st));
		strcpy( tmp->start_time, start_time);
		strcpy( tmp->stop_time, stop_time);
		tmp->next = *ptr;
		*ptr = tmp;
		return 0;
	} else {
		tmp = *ptr;
		while(tmp) {			
			diff_starttime = get_diff_time(tmp->start_time, start_time);
			if(tmp->next != NULL) {
				diff_next_start_time = get_diff_time(tmp->next->start_time, start_time);
			}

			if((diff_starttime == 2 && tmp->next == NULL) || (diff_next_start_time == 1) ) {
				tmp1 = malloc(sizeof(struct st));
				strcpy(tmp1->start_time, start_time);
				strcpy(tmp1->stop_time, stop_time);
				tmp1->next = tmp->next;
	           		tmp->next = tmp1;
				return 0;
			} 
			tmp = tmp->next; 
		}
	}


}

static int schedule_merge( struct st **ptr) 
{
	int diff_starttime, diff_stoptime, diff_stop_start_time, diff_start_stop_time, diff_next_start_time;
	struct st *tmp, *tmp1;
		tmp = *ptr;
		while( tmp != NULL && tmp->next != NULL) {			
			diff_stoptime = get_diff_time(tmp->stop_time, tmp->next->stop_time);
			diff_stop_start_time = get_diff_time(tmp->stop_time, tmp->next->start_time);

			if(diff_stop_start_time == 2) {
				tmp = tmp->next;
			}

			/* Free next node */
			else if ( diff_stop_start_time <= 1 && diff_stoptime <= 1) {
				tmp1 = tmp->next;
				tmp->next = tmp1->next;
				free(tmp1);
			}
			else if ( diff_stoptime == 2 ) {
			/* Change Stop time for same day */
				tmp1 = tmp->next;
				tmp->next = tmp1->next;
				strcpy(tmp->stop_time,tmp1->stop_time);
				free(tmp1);
			}
		}


}

/*static int update_struct_tbs_day( struct st **ptr, char *start_time, char *stop_time) 
{
	int diff_starttime, diff_stoptime, diff_stop_start_time, diff_start_stop_time, diff_next_start_time;
	struct st *tmp, *tmp1;
	printf("NIKHIL---------> %s %s\n",start_time,stop_time);

	if( *ptr != NULL) {
		diff_start_stop_time = 0; 
		diff_start_stop_time = get_diff_time((*ptr)->start_time, stop_time);
		printf("ADD at start NIKHIL-------> %d\n",diff_start_stop_time);
	}
	if( *ptr == NULL || diff_start_stop_time == 1) {
		/// Timer add first time /
		printf("\nTEST----NULL\n");
		tmp = malloc(sizeof(struct st));
		strcpy( tmp->start_time, start_time);
		strcpy( tmp->stop_time, stop_time);
		tmp->next = *ptr;
		*ptr = tmp;
		return 0;
	} else {
		tmp = *ptr;
		while(tmp) {			
			diff_starttime = get_diff_time(tmp->start_time, start_time);
			diff_stoptime = get_diff_time(tmp->stop_time, stop_time);
			diff_stop_start_time = get_diff_time(tmp->stop_time, start_time);
			diff_start_stop_time = get_diff_time(tmp->start_time, stop_time);
			diff_next_start_time = 0;

			if(tmp->next != NULL) {
				diff_next_start_time = get_diff_time(tmp->next->start_time, stop_time);
			}
			if ( (diff_starttime == 0  || diff_starttime == 2 ) && (diff_stoptime == 0 || diff_stoptime == 1 ) ) {
				printf("\nTEST11----------\n");
				return 0;
			}
			//*Change start time for same day 
			else if ( diff_starttime == 1 && diff_stoptime == 1 && diff_start_stop_time == 2) {
				printf("\nTEST2----\n");
				strcpy(tmp->start_time, start_time);
				return 0;
			}
			// Change Stop time for same day 
			else if ( (diff_starttime == 0 || diff_starttime == 2) && diff_stoptime == 2 && 
				  (diff_stop_start_time == 0 || diff_stop_start_time == 1) ) {
				printf("\nTEST3----\n");
				strcpy(tmp->stop_time, stop_time);
				return 0;
			}
			// Change start time and stop time for same day 
			else if(diff_starttime == 1 && diff_stoptime == 2) {
				printf("\nTEST4----\n");
				strcpy(tmp->start_time, start_time);
				strcpy(tmp->stop_time, stop_time);
				return 0;
			}
			else if((diff_stop_start_time == 2 && tmp->next == NULL) || (diff_next_start_time == 1) ) {

				printf("\nTEST6----\n");
				tmp1 = malloc(sizeof(struct st));
				strcpy(tmp1->start_time, start_time);
				strcpy(tmp1->stop_time, stop_time);
				tmp1->next = tmp->next;
				tmp->next = tmp1;
				return 0;
			} 
			tmp = tmp->next; 
			printf("\nTEST---- END\n");
		}
	}


}

*/


/* Calculate the time string for time based scan */
static int get_time_select(int n_scheduleid )
{
        int i, j = 0, k, days, arraylen;
        char schedule_obj_req_str[128];
	char time_select[4096]= {0};
        char start_time[8][8] = {"5:00","4:23","10:30","5:00","1:00","9:50","23:00"};
	char stop_time[8][8] = {"9:50","6:40","14:00","9:00","3:00","10:30","23:52" };
        char startime[8], stoptime[8], enable[8] = { }, src[32] = {};
        char week[7][8] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	struct st *tmp,*tmp1;
	struct st *weekday[7] = { NULL };
        for (i=0; i < n_scheduleid; i++) {
                                        days = 7;
                                        if (days < 8) {
						add_sort(&weekday[days - 1 ], start_time[j], stop_time[j]);
					//	update_struct_tbs_day(&weekday[days - 1 ], start_time[j], stop_time[j]);

                                        } else if ( days == 8  || days == 9 || days == 10) {
                                                if( days == 10) {
                                                        k = 0;
                                                        days--;
                                                } else {
                                                        k = 1;
                                                }
                                                for ( ; k < days-2; k++) {
							add_sort(&weekday[k ], start_time[j], stop_time[j]);
						//	update_struct_tbs_day(&weekday[k ], start_time[j], stop_time[j]);
                                                }
                                        }
		j++;
        }
        j = 0;
        for (i=0; i < 7; i++) {
		tmp = weekday[i ];
			while(tmp) {	
                        	if (j == 0) {
                                	sprintf(src,"%s:%s-%s:%s", week[i], tmp->start_time, week[i], tmp->stop_time);
                                	j++;
                        	} else {
                                	sprintf(src,",%s:%s-%s:%s", week[i], tmp->start_time, week[i], tmp->stop_time);
                        	}
                        	strcat(time_select, src);
				tmp = tmp->next;
			}
        }

	printf("\n\n%s\n",time_select);
	memset(time_select,'\0',sizeof(time_select));

	for (i=0; i < 7; i++) {
		schedule_merge(&weekday[i]);
	}

      j = 0;
        for (i=0; i < 7; i++) {
		tmp = weekday[i ];
			while(tmp) {	
                        	if (j == 0) {
                                	sprintf(src,"%s:%s-%s:%s", week[i], tmp->start_time, week[i], tmp->stop_time);
                                	j++;
                        	} else {
                                	sprintf(src,",%s:%s-%s:%s", week[i], tmp->start_time, week[i], tmp->stop_time);
                        	}
                        	strcat(time_select, src);
				tmp = tmp->next;
			}
        }


	 for (i=0; i < 7; i++) {
                while (weekday[i] != NULL) {
                        tmp = weekday[i];
                        weekday[i] = weekday[i]->next;
                        free(tmp);
                }
        }

	printf("\n\n%s\n",time_select);
        return 0;
}

main() {
	get_time_select(7);

}
