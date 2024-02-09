#include <stdio.h>
#include <assert.h>
typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;
void printstudent(Student* s, FILE* fp) {
    char str[100];
    fputs("<tr>\n", fp);
    sprintf(str, "<td>%s</td>\n", s->name);
    fputs(str, fp);
    sprintf(str, "<td>%d</td>\n", s->id);
    fputs(str, fp);
    sprintf(str, "<td>%s</td>\n", s->phone);
    fputs(str, fp);
    sprintf(str, "<td>%f, %f, %f, %f</td>\n", s->grade[0], s->grade[1], s->grade[2], s->grade[3]);
    fputs(str, fp);
    sprintf(str, "<td>%d, %d, %d</td>\n", s->birth_year, s->birth_month, s->birth_day);
    fputs(str, fp);
    fputs("</tr>\n", fp);
}
int main() {
    FILE* fp, * fp_; char binfilename[80], htmlfilename[80], c = '"'; Student a;
    char str[100]; static char buf[1 << 15];
    scanf("%s", binfilename);
    scanf("%s", htmlfilename);       
    fp = fopen(binfilename, "rb");
    fp_ = fopen(htmlfilename, "wb+");
    assert(fp);
    assert(fp_);
    fseek(fp, 0, SEEK_SET);
    sprintf(str, "<table border=%c1%c>\n", c, c);
    fputs(str, fp_);
    fputs("<tbody>\n", fp_);
    while (fread(&a, sizeof(Student), 1, fp) > 0) {
        printstudent(&a, fp_);
        fseek(fp, 0, SEEK_CUR);
    }
    fputs("</tbody>\n", fp_);
    fputs("</table>", fp_);
    fclose(fp);
    fclose(fp_);
    fp_ = fopen(htmlfilename, "rb");
    assert(fp_);
    fread(buf, sizeof(char), 1 << 15, fp_);
    printf("%s", buf);
    fclose(fp_);
    return 0;
}