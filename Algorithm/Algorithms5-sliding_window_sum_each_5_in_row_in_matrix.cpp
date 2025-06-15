/*  in   –  מצביע לתחילת המטריצה בגודל rows × cols (row-major)
 *  rows –  מספר השורות
 *  cols –  מספר העמודות  (חייב להיות ≥ 5)
 *  out  –  מערך פלט בגודל rows × (cols-4)
 *          הסכומים נכתבים באותו סדר שורות.
 *          עבור שורה i (0-based) התא out[ i*(cols-4) + j ]
 *          מכיל  a[i][j] + … + a[i][j+4]
 */



 void sum_each_5_in_line_simplify(int*in, int rows, int cols, int*out)
 {   //O(rows*cols)
    const int slide_by = 5;
     if (cols < slide_by /*5*/ || rows <= 0) return;          /* אין חלון חוקי */
 
     int outCols = cols - slide_by-1; /*cols-5-1*/                    /* כמה חלונות בכל שורה */
 
     for (int r = 0; r < rows; ++r)
     {
         /* מצביע לתחילת השורה הנוכחית */
         const int pos = r * cols; //row pos  in 1D array
 
         const int out_pos = r * outCols;   //cols - 4
 
         /* סכום החלון הראשון (עמודות 0..4) */
         int cur = in[pos+0] + in[pos+1] + in[pos+2] + in[pos+3] + in[pos+4];
         out[out_pos+0] = cur;
         //out[r * outCols + 0] = cur;
 
         /* חלונות הבאים: O(1) לעדכון */
         for (int c = 1; c < outCols; ++c)  //cols - 4
         {
             int cur = out[out_pos + c - 1];
             cur += in[pos + c + 4];
             cur -= in[pos + c - 1]; /* מוסיף נכנס, מוריד יוצא */
             out[out_pos + c] = cur;
         }
     }
 }
 
 



void sum_each_5_in_line(int*in, int rows, int cols, int*out)
{   //O(rows*cols)
    if (cols < 5 || rows <= 0) return;          /* אין חלון חוקי */

    int outCols = cols - 4;                     /* כמה חלונות בכל שורה */

    for (int r = 0; r < rows; ++r)
    {
        /* מצביע לתחילת השורה הנוכחית */
        const int* pos = in + r * cols; //row pos  in 1D array

        int* dst = out + r * outCols;

        /* סכום החלון הראשון (עמודות 0..4) */
        int first = pos[0] + pos[1] + pos[2] + pos[3] + pos[4];
        dst[0] = first;
        //out[r * outCols + 0] = cur;

        /* חלונות הבאים: O(1) לעדכון */
        for (int c = 1; c < outCols; ++c)
        {
            int cur = dst[c - 1];
            cur += pos[c + 4];
            cur -= pos[c - 1]; /* מוסיף נכנס, מוריד יוצא */
            dst[c]=cur;
        }
    }
}



/*  in   –  מטריצה רציפה בגודל rows × cols  (Row-Major)
 *  out  –  גודל rows × (cols-4)          (חלון 5-עמודות לכל שורה)
 *
 *  זמן   O(rows·cols)      זיכרון נוסף O(1)
 */
void sum_each_5_in_line(int* in, int rows, int cols, int* out)
{
    if (rows <= 0 || cols < 5) return;          /* אין חלון חוקי */

    const int outCols = cols - 4;               /* חלונות בכל שורה */

    for (int r = 0; r < rows; ++r)
    {
        int*          dst = out + r * outCols;  /* התחלה בשורת הפלט */
        const int*    src = in  + r * cols;     /* התחלה בשורת הקלט */

        /* --- סכום חלון ראשון (עמודות 0..4) ------------------------ */
        int cur = src[0] + src[1] + src[2] + src[3] + src[4];
        dst[0] = cur;

        /* --- מחליקים ימינה  --------------------------------------- */
        for (int c = 1; c < outCols; ++c)
        {
            cur += src[c + 4];   /* איבר חדש שנכנס */
            cur -= src[c - 1];  /* איבר ישן שיצא  */
            dst[c] = cur;
        }
    }
}
