// > gcc -W -Wall -noixemul ?.c

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>

#include <clib/alib_protos.h>

//#define extra_row

int main(void)
{
	Object *application, *spr_window, *single_bits[101];

	for (int i = 0; i < 101; i++)
	{
		single_bits[i] = MUI_NewObject(MUIC_Text, 
							MUIA_InputMode, MUIV_InputMode_Toggle, 
							MUIA_Text_Contents, "0", 
							MUIA_FixWidthTxt, "0", 
							MUIA_ShowSelState, FALSE, TAG_END);

		DoMethod(single_bits[i], MUIM_Notify, MUIA_Selected, TRUE, single_bits[i], 3, MUIM_Set, MUIA_Text_Contents, "1");
		DoMethod(single_bits[i], MUIM_Notify, MUIA_Selected, FALSE, single_bits[i], 3, MUIM_Set, MUIA_Text_Contents, "0");
	}

	if ((application = MUI_NewObject(MUIC_Application, MUIA_Application_Window, spr_window = 
		MUI_NewObject(MUIC_Window, MUIA_Window_Title, "Special Purpose Registers & Condidtion Registers", 
			MUIA_Window_RootObject, MUI_NewObject(MUIC_Group, MUIA_Group_Spacing, 0, 

				/* 1st horizontal group */ 
				MUIA_Group_Child, MUI_NewObject(MUIC_Group, MUIA_Group_VertSpacing, 0, MUIA_Group_Horiz, TRUE, 

					MUIA_Group_Child, 
					MUI_NewObject(MUIC_Group, MUIA_Group_HorizCenter, 0 /* left align */, MUIA_Group_VertSpacing, 0, 

						MUIA_Group_Child, 
						MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 1, 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "\33bXER", MUIO_Label_LeftAligned), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "spr1", MUIO_Label_Centered|MUIO_Label_Tiny), 
						TAG_END), 

						MUIA_Group_Child, 
						MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 3, MUIA_Group_VertSpacing, 0, 

							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "0", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 

							MUIA_Group_Child, single_bits[98], 
							MUIA_Group_Child, single_bits[99], 
							MUIA_Group_Child, single_bits[100], 

							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "OV", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "CR", MUIO_Label_Centered|MUIO_Label_Tiny), 

						TAG_END), 
					TAG_END), /* end of Group : XER part 1 */

					MUIA_Group_Child, 
					MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 4, MUIA_Group_VertSpacing, 0, 

						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 

						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "**", MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3 ··· 24", MUIO_Label_Centered|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "**", MUIO_Label_Tiny), 

						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "**", MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "Reserved", MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "**", MUIO_Label_Tiny), 

						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 

					TAG_END), /* end of Group : XER part 2 */

					MUIA_Group_Child, 
					MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 4, MUIA_Group_VertSpacing, 0, 

						MUIA_Group_Child, 
							MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 1, 
								MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "lswx stswx", MUIO_Label_Centered|MUIO_Label_Tiny), 
								MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
							TAG_END), 

						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "25 ··· 31", MUIO_Label_Centered|MUIO_Label_Tiny), 

						MUIA_Group_Child, 
							MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 1, 
								MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "0x00", MUIO_Label_LeftAligned), 
								MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "  (0)", 0), 
							TAG_END), 

						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "byte count", MUIO_Label_Centered|MUIO_Label_Tiny),

					TAG_END), /* end of Group : XER part 3 */

					MUIA_Group_Child, 
					MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 4, MUIA_Group_VertSpacing, 0, 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "\33bLR", MUIO_Label_LeftAligned), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "spr8", MUIO_Label_LeftAligned|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "xxxxxxxx", 0), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 
					TAG_END), /* end of Group : LR */

					MUIA_Group_Child, 
					MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 4, MUIA_Group_VertSpacing, 0, 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "\33bCTR", MUIO_Label_LeftAligned), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "spr9", MUIO_Label_LeftAligned|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "xxxxxxxx", 0), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 
					TAG_END), /* end of Group : CTR */

					MUIA_Group_Child, 
					MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 4, MUIA_Group_VertSpacing, 0, 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "\33bTBU", MUIO_Label_LeftAligned), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "spr269", MUIO_Label_LeftAligned|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "xxxxxxxx", 0), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 
					TAG_END), /* end of Group : TBU */

					MUIA_Group_Child, 
					MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 4, MUIA_Group_VertSpacing, 0, 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "\33bTBL", MUIO_Label_LeftAligned), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "spr268", MUIO_Label_LeftAligned|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "xxxxxxxx", 0), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 
					TAG_END), /* end of Group : TBL */ 

				TAG_END), /* end of the 1st horizontal group */

				/* 2nd horizontal group */
				MUIA_Group_Child, MUI_NewObject(MUIC_Group, MUIA_Group_VertSpacing, 0, MUIA_Group_Horiz, TRUE, 

					MUIA_Group_Child, 
					MUI_NewObject(MUIC_Group, MUIA_Group_HorizCenter, 0, MUIA_Group_VertSpacing, 0, 

						MUIA_Group_Child, 
						MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 1, 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "\33bVRSAVE", MUIO_Label_LeftAligned), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "spr256", MUIO_Label_LeftAligned|MUIO_Label_Tiny), 
						TAG_END), 

						MUIA_Group_Child, 
						MUI_NewObject(MUIC_Group, 
							MUIA_Group_Columns, 32, 
							MUIA_Group_VertSpacing, 0, 
							MUIA_Group_SameWidth, TRUE, 

							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "0", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "4", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "5", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "6", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "7", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "8", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "9", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "10", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "11", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "12", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "13", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "14", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "15", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "16", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "17", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "18", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "19", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "20", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "21", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "22", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "23", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "24", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "25", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "26", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "27", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "28", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "29", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "30", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "31", MUIO_Label_Centered|MUIO_Label_Tiny), 

							MUIA_Group_Child, single_bits[64], 
							MUIA_Group_Child, single_bits[65], 
							MUIA_Group_Child, single_bits[66], 
							MUIA_Group_Child, single_bits[67], 
							MUIA_Group_Child, single_bits[68], 
							MUIA_Group_Child, single_bits[69], 
							MUIA_Group_Child, single_bits[70], 
							MUIA_Group_Child, single_bits[71], 
							MUIA_Group_Child, single_bits[72], 
							MUIA_Group_Child, single_bits[73], 
							MUIA_Group_Child, single_bits[74], 
							MUIA_Group_Child, single_bits[75], 
							MUIA_Group_Child, single_bits[76], 
							MUIA_Group_Child, single_bits[77], 
							MUIA_Group_Child, single_bits[78], 
							MUIA_Group_Child, single_bits[79], 
							MUIA_Group_Child, single_bits[80], 
							MUIA_Group_Child, single_bits[81], 
							MUIA_Group_Child, single_bits[82], 
							MUIA_Group_Child, single_bits[83], 
							MUIA_Group_Child, single_bits[84], 
							MUIA_Group_Child, single_bits[85], 
							MUIA_Group_Child, single_bits[86], 
							MUIA_Group_Child, single_bits[87], 
							MUIA_Group_Child, single_bits[88], 
							MUIA_Group_Child, single_bits[89], 
							MUIA_Group_Child, single_bits[90], 
							MUIA_Group_Child, single_bits[91], 
							MUIA_Group_Child, single_bits[92], 
							MUIA_Group_Child, single_bits[93], 
							MUIA_Group_Child, single_bits[94], 
							MUIA_Group_Child, single_bits[95], 

#ifdef extra_row
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
							MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
#endif

						TAG_END), 
					TAG_END), /* end of VRSAVE */

					MUIA_Group_Child, 
//					MUI_NewObject(MUIC_Group, MUIA_Group_Rows, 3, MUIA_Group_VertSpacing, 0, 
					MUI_NewObject(MUIC_Group, MUIA_Group_Columns, 4, MUIA_Group_VertSpacing, 0, 

						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "\33bVSCR", MUIO_Label_LeftAligned), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "NJ", MUIO_Label_LeftAligned|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SAT", MUIO_Label_LeftAligned|MUIO_Label_Tiny), 

						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "0·14", MUIO_Label_Centered|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "15", MUIO_Label_Centered|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "16·30", MUIO_Label_Centered|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "31", MUIO_Label_Centered|MUIO_Label_Tiny), 

						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "--", MUIO_Label_Centered), 
						MUIA_Group_Child, single_bits[96], 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "--", MUIO_Label_Centered), 
						MUIA_Group_Child, single_bits[97], 

#ifdef extra_row
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
						MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
#endif

					TAG_END), 

				TAG_END), /* end of the 2nd horizontal group */

				MUIA_Group_Child, 
				MUI_NewObject(MUIC_Group, MUIA_Group_Horiz, TRUE, MUIA_Group_Spacing, 0, 

					MUIA_Group_Child, 
					MUI_NewObject(MUIC_Group, MUIA_Group_Horiz, TRUE, MUIA_Group_Spacing, 0, MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 7, 
						MUIA_Group_Child, MUI_NewObject(MUIC_Text, MUIA_Text_Contents, "\33l\33bFPSCR", MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 2, TAG_END), 
						MUIA_Group_Child, MUI_NewObject(MUIC_Text, MUIA_Text_Contents, "exception summary", MUIA_Font, MUIV_Font_Tiny, MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 5, TAG_END), 
					TAG_END), 

					MUIA_Group_Child, MUI_NewObject(MUIC_Text, MUIA_Text_Contents, "\33cinValid operation eXception", MUIA_Font, MUIV_Font_Tiny, MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 6, TAG_END), 
					MUIA_Group_Child, MUI_NewObject(MUIC_Text, MUIA_Text_Contents, "\33cfraction", MUIA_Font, MUIV_Font_Tiny, MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 2, TAG_END), 
					MUIA_Group_Child, MUI_NewObject(MUIC_Text, MUIA_Text_Contents, "\33cFPRF", MUIA_Font, MUIV_Font_Tiny, MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 5, TAG_END), 
					MUIA_Group_Child, MUI_NewObject(MUIC_Text, MUIA_Text_Contents, "", MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 1, TAG_END), 
					MUIA_Group_Child, MUI_NewObject(MUIC_Text, MUIA_Text_Contents, "\33cVX", MUIA_Font, MUIV_Font_Tiny, MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 3, TAG_END), 
					MUIA_Group_Child, MUI_NewObject(MUIC_Text, MUIA_Text_Contents, "\33cexception enable", MUIA_Font, MUIV_Font_Tiny, MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 5, TAG_END), 
					MUIA_Group_Child, MUI_NewObject(MUIC_Text, MUIA_Text_Contents, "", MUIA_Frame, MUIV_Frame_None, MUIA_Weight, 3, TAG_END), 

				TAG_END), 

				MUIA_Group_Child, 
				MUI_NewObject(MUIC_Group, MUIA_Group_Columns, 32, MUIA_Group_Spacing, 0, MUIA_Group_SameWidth, TRUE, 

					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FEX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "VX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "OX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "UX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "ZX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "XX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SNN", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "ISI", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "IDI", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "ZDZ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "IMZ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "VC", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FR", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FI", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "C", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "<", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, ">", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "=", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "?", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "--", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SFT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SQR", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "CVI", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "VE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "OE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "UE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "ZE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "XE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "NI", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "R", MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "N", MUIO_Label_LeftAligned|MUIO_Label_Tiny), 

					MUIA_Group_Child, single_bits[32], 
					MUIA_Group_Child, single_bits[33], 
					MUIA_Group_Child, single_bits[34], 
					MUIA_Group_Child, single_bits[35], 
					MUIA_Group_Child, single_bits[36], 
					MUIA_Group_Child, single_bits[37], 
					MUIA_Group_Child, single_bits[38], 
					MUIA_Group_Child, single_bits[39], 
					MUIA_Group_Child, single_bits[40], 
					MUIA_Group_Child, single_bits[41], 
					MUIA_Group_Child, single_bits[42], 
					MUIA_Group_Child, single_bits[43], 
					MUIA_Group_Child, single_bits[44], 
					MUIA_Group_Child, single_bits[45], 
					MUIA_Group_Child, single_bits[46], 
					MUIA_Group_Child, single_bits[47], 
					MUIA_Group_Child, single_bits[48], 
					MUIA_Group_Child, single_bits[49], 
					MUIA_Group_Child, single_bits[50], 
					MUIA_Group_Child, single_bits[51], 
					MUIA_Group_Child, single_bits[52], 
					MUIA_Group_Child, single_bits[53], 
					MUIA_Group_Child, single_bits[54], 
					MUIA_Group_Child, single_bits[55], 
					MUIA_Group_Child, single_bits[56], 
					MUIA_Group_Child, single_bits[57], 
					MUIA_Group_Child, single_bits[58], 
					MUIA_Group_Child, single_bits[59], 
					MUIA_Group_Child, single_bits[60], 
					MUIA_Group_Child, single_bits[61], 
					MUIA_Group_Child, single_bits[62], 
					MUIA_Group_Child, single_bits[63], 

					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "0", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "4", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "5", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "6", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "7", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "8", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "9", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "10", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "11", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "12", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "13", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "14", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "15", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "16", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "17", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "18", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "19", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "20", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "21", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "22", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "23", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "24", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "25", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "26", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "27", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "28", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "29", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "30", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "31", MUIO_Label_Centered|MUIO_Label_Tiny), 

					MUIA_Group_Child, single_bits[0], 
					MUIA_Group_Child, single_bits[1], 
					MUIA_Group_Child, single_bits[2], 
					MUIA_Group_Child, single_bits[3], 
					MUIA_Group_Child, single_bits[4], 
					MUIA_Group_Child, single_bits[5], 
					MUIA_Group_Child, single_bits[6], 
					MUIA_Group_Child, single_bits[7], 
					MUIA_Group_Child, single_bits[8], 
					MUIA_Group_Child, single_bits[9], 
					MUIA_Group_Child, single_bits[10], 
					MUIA_Group_Child, single_bits[11], 
					MUIA_Group_Child, single_bits[12], 
					MUIA_Group_Child, single_bits[13], 
					MUIA_Group_Child, single_bits[14], 
					MUIA_Group_Child, single_bits[15], 
					MUIA_Group_Child, single_bits[16], 
					MUIA_Group_Child, single_bits[17], 
					MUIA_Group_Child, single_bits[18], 
					MUIA_Group_Child, single_bits[19], 
					MUIA_Group_Child, single_bits[20], 
					MUIA_Group_Child, single_bits[21], 
					MUIA_Group_Child, single_bits[22], 
					MUIA_Group_Child, single_bits[23], 
					MUIA_Group_Child, single_bits[24], 
					MUIA_Group_Child, single_bits[25], 
					MUIA_Group_Child, single_bits[26], 
					MUIA_Group_Child, single_bits[27], 
					MUIA_Group_Child, single_bits[28], 
					MUIA_Group_Child, single_bits[29], 
					MUIA_Group_Child, single_bits[30], 
					MUIA_Group_Child, single_bits[31], 

					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FL", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FG", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FU", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FL", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FG", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FU", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FL", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FG", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FU", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FL", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FG", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FU", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FL", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FG", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FU", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FL", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FG", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FU", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FL", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FG", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FU", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FL", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FG", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FE", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FU", MUIO_Label_Centered|MUIO_Label_Tiny), 

					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "LT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "GT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "EQ", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "SO", MUIO_Label_Centered|MUIO_Label_Tiny), 

					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "0:0", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1:0", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2:0", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3:0", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "4:0", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "5:0", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "6:0", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "7:0", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "1", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "2", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "3", MUIO_Label_Centered|MUIO_Label_Tiny), 

					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "\33bCR", MUIO_Label_LeftAligned), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "FEX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "VX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "OX", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "VT", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "VF", MUIO_Label_Centered|MUIO_Label_Tiny), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 
					MUIA_Group_Child, MUI_MakeObject(MUIO_Label, "", 0), 


				TAG_END), /* end of 32 columns */

			TAG_END), /* end of the Window_RootObject : Group */
		TAG_END), /* end of Window */
	TAG_END) /* end of application */ ))
	{
		DoMethod(spr_window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, (ULONG) application, 2, 
			MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

		for (int i = 0; i < 101; i++)
		{
			DoMethod(single_bits[i], MUIM_Notify, MUIA_Selected, TRUE, application, 2, MUIM_Application_ReturnID, (i * 2) + 1);
			DoMethod(single_bits[i], MUIM_Notify, MUIA_Selected, FALSE, application, 2, MUIM_Application_ReturnID, (i * 2) + 2);
		}

		set((APTR) spr_window, MUIA_Window_Open, TRUE);

		ULONG signals = 0, DMresult, constant;

		DoMethod(application, MUIM_Application_NewInput, &constant);

		while ((int) (DMresult = DoMethod(application, MUIM_Application_NewInput, &signals)) != MUIV_Application_ReturnID_Quit)
		{
			if (DMresult != 0) DisplayBeep(0);

			if ((signals = Wait(signals | SIGBREAKF_CTRL_C | constant)) == SIGBREAKF_CTRL_C) break;
		}

		set((APTR) spr_window, MUIA_Window_Open, FALSE);

		MUI_DisposeObject(application);	
	}

	return (0);
}