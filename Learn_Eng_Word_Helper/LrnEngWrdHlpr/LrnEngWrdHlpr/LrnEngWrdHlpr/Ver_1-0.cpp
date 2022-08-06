#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

char Eng[100][100] = { 0 };		//English
char Kor[100][100] = { 0 };		//Korean

int wrd = 0;
int loop = 0;

void main() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

	printf("\"0 0\" �Է����� �ܾ �׸� �Է� �� �� �ֽ��ϴ�, ����� \'_\'�� �Է��� �ּ���. \n");

	while (1) {
		wrd++;
		printf("\n\n\"Eng Kor\" �ܾ� �Է� %d. ", wrd);
		scanf("%s %s", Eng[wrd - 1], Kor[wrd - 1]);

		if (Eng[wrd - 1][0] == '0' && Kor[wrd - 1][0] == '0') {
			wrd--;
			printf("\n�Է��� �ܾ� ����: %d, [wrdAdd] ��ɾ�� �� �߰��� �� �ֽ��ϴ�. \n\n", wrd);

			if (wrd == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

				printf("\n�߰��� �ܾ �����ϴ�. 3�� �� �ڵ����� ���α׷��� �����մϴ�. \n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				Sleep(3000);
				return;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			break;
		}
	}

	while (1) {
		char cmd[15] = { 0 };

		srand(time(NULL));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		printf("\n\"help\"�� �Է��Ͽ� ���� ��ɾ���� �� �� �ֽ��ϴ� \n> ");
		
		scanf("%s", cmd);

		/*====================*/

		/*=== ���� ===*/		// help = ���� ���
		if(strcmp(cmd, "help") == 0) {		//strcmp�� ���� ���̸� '0', �����̸� '-1'�� ����Ѵ�. (�� ����..)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

			printf("\nLearn English Word Helper 1.0v ���� \n\n\n");
			printf("\n[�ܾ� �ܿ��] \n\n");
			printf("EngType1 \n���ܾ �Է��� ������� ������, �ѱ�� �Է��ؾ� �մϴ�. \n\nEngType2 \n���ܾ �� �������� ������� ������, �ѱ�� �Է��ؾ��մϴ�. \n\nEngType3 \n���ܾ ���ܾ� ���� x 2 ��ŭ �������� ���ɴϴ�. \(�� ������ �ܾ ������ �� ����\)\n\n");
			printf("KorType1 \n�ѱ��� �Է��� ������� ������, ��� �Է��ؾ� �մϴ�. \n\nKorType2 \n�ѱ��� �� �������� ������� ������, ��� �Է��ؾ� �մϴ�. \n\nKorType3 \n�ѱ��� �ѱ� ���� x 2 ��ŭ �������� ���ɴϴ�. \(�� ������ �ܾ ������ �� ����\) \n\n\n");
			printf("\n[�ܾ� �߰�/����] \n\n");
			printf("wrd \n����� �ܾ �� �� �ֽ��ϴ�. \n\n");
			printf("wrdAdd \n���ο� �ܾ ���� �ܾ�� �Բ� �߰��մϴ�. \n\nwrdDellAll \n��� �ܾ ����� �ٽ� �����մϴ�. \n\nWrdDelPrt \n���ϴ� �ܾ� �ϳ��� ����ϴ�. \n\n\n");
			printf("\n[���� �� ��Ÿ] \n\n");
			printf("prgmFnsh / PF \n���α׷��� �����մϴ�. \n\nDEL \n��� ������ �����մϴ�. \n\nVerChk \n���� ������ Ȯ�� �� �� �ֽ��ϴ�. \n\n");
			printf("mail \n�������� ������ �� �� �ֽ��ϴ� \n\nGitHub \n�� ������ ����Ǿ� �ִ� C-Language �������丮 ��ũ�� �������ϴ�. \n\nLink \n�������� SNS ��ũ���� �� �� �ֽ��ϴ�. \n\ncredits \n���ۿ� ������ �ֽ� �е��� �� �� �ֽ��ϴ�. \n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*=== �ܾ� �ܿ�� ===*/		// EngType1/KorType1 = 1 ~ N ������ ��/�ѱ� �ܾ� ���, EngType2/KorType2 = EngType1�� ����, N ~ 1�� �ٸ�, EngType3/KorType3 = �տ��� ������ N * 2��ŭ �������� ��/�ѱ۴ܾ ���� (�� ������ �� ����)
		else if(strcmp(cmd, "EngType1") == 0) {
			int crect = 0;

			system("cls");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("EngType1 �ܾ� �׽�Ʈ�� �����մϴ�. \n");

			crect = 0;
			int wrng[100] = { 0 };
			int w = 0;

			for (int q = 0; q < wrd; q++) {
				printf("\n%d. %s: ", (q + 1), Eng[q]);

				char ans[100] = { 0 };

				scanf("%s", ans);

				if (strcmp(ans, Kor[q]) == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					printf("correct \n");
					crect++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("wrong answer \n");
					wrng[w] = q;
					w++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				}
			}

			printf("%d���� �� %d���� �¾ҽ��ϴ�. \n\n", wrd, crect);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			for (int q = 0; q < w; q++) {
				printf("%d. %s %s \n", (q + 1), Eng[wrng[q]], Kor[wrng[q]]);
			}

			printf("\n\n\n");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "EngType2") == 0) {
			int crect = 0;

			system("cls");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("EngType2 �ܾ� �׽�Ʈ�� �����մϴ�. \n");

			crect = 0;
			int wrng[100] = { 0 };
			int w = 0;

			for (int q = (wrd - 1); q >= 0; q--) {
				printf("\n%d. %s: ", (q + 1), Eng[q]);

				char ans[100] = { 0 };

				scanf("%s", ans);

				if (strcmp(ans, Kor[q]) == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					printf("correct \n");
					crect++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("wrong answer \n");
					wrng[w] = q;
					w++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				}
			}

			printf("%d���� �� %d���� �¾ҽ��ϴ�. \n\n", wrd, crect);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			for (int q = 0; q < w; q++) {
				printf("%d. %s %s \n", (q + 1), Eng[wrng[q]], Kor[wrng[q]]);
			}

			printf("\n\n\n");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "EngType3") == 0) {
		int crect = 0;

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("EngType3 �ܾ� �׽�Ʈ�� �����մϴ�. \n");

		crect = 0;
		int wrng[100] = { 0 };
		int w = 0;

		for (int q = 0; q < (wrd * 2); q++) {
			int rnd = rand() % wrd;

			printf("\n%d. %s: ", (q + 1), Eng[rnd]);

			char ans[100] = { 0 };

			scanf("%s", ans);

			if (strcmp(ans, Kor[rnd]) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("correct \n");
				crect++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("wrong answer \n");
				wrng[w] = rnd;
				w++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
		}

		printf("%d���� �� %d���� �¾ҽ��ϴ�. \n\n", (wrd * 2), crect);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int q = 0; q < w; q++) {
			printf("%d. %s %s \n", (q + 1), Eng[wrng[q]], Kor[wrng[q]]);
		}

		printf("\n\n\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "KorType1") == 0) {
		int crect = 0;

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("KorType1 �ܾ� �׽�Ʈ�� �����մϴ�. \n");

		crect = 0;
		int wrng[100] = { 0 };
		int w = 0;

		for (int q = 0; q < wrd; q++) {
			printf("\n%d. %s: ", (q + 1), Kor[q]);

			char ans[100] = { 0 };

			scanf("%s", ans);

			if (strcmp(ans, Eng[q]) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("correct \n");
				crect++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("wrong answer \n");
				wrng[w] = q;
				w++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
		}

		printf("%d���� �� %d���� �¾ҽ��ϴ�. \n\n", wrd, crect);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int q = 0; q < w; q++) {
			printf("%d. %s %s \n", (q + 1), Kor[wrng[q]], Eng[wrng[q]]);
		}

		printf("\n\n\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "KorType2") == 0) {
		int crect = 0;

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("KorType2 �ܾ� �׽�Ʈ�� �����մϴ�. \n");

		crect = 0;
		int wrng[100] = { 0 };
		int w = 0;

		for (int q = (wrd - 1); q >= 0; q--) {
			printf("\n%d. %s: ", (q + 1), Kor[q]);

			char ans[100] = { 0 };

			scanf("%s", ans);

			if (strcmp(ans, Eng[q]) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("correct \n");
				crect++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("wrong answer \n");
				wrng[w] = q;
				w++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
		}

		printf("%d���� �� %d���� �¾ҽ��ϴ�. \n\n", wrd, crect);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int q = 0; q < w; q++) {
			printf("%d. %s %s \n", (q + 1), Kor[wrng[q]], Eng[wrng[q]]);
		}

		printf("\n\n\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "KorType3") == 0) {
		int crect = 0;

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("KorType3 �ܾ� �׽�Ʈ�� �����մϴ�. \n");

		crect = 0;
		int wrng[100] = { 0 };
		int w = 0;

		for (int q = 0; q < (wrd * 2); q++) {
			int rnd = rand() % wrd;

			printf("\n%d. %s: ", (q + 1), Kor[rnd]);

			char ans[100] = { 0 };

			scanf("%s", ans);

			if (strcmp(ans, Eng[rnd]) == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printf("correct \n");
				crect++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("wrong answer \n");
				wrng[w] = rnd;
				w++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			}
		}

		printf("%d���� �� %d���� �¾ҽ��ϴ�. \n\n", (wrd * 2), crect);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int q = 0; q < w; q++) {
			printf("%d. %s %s \n", (q + 1), Kor[wrng[q]], Eng[wrng[q]]);
		}

		printf("\n\n\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*=== �ܾ� �߰�/���� ===*/	// wrd = ������ �ܾ� ����, wrdAdd = �ܾ� �߰�, wrdDelAll = �ܾ� ��ü ���� �� �ٽ� �Է�, wrdDelPrt = Ư�� �κ� �ܾ� ����
		else if (strcmp(cmd, "wrd") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			for (int q = 0; q < wrd; q++) {
				printf("\n%d. %s %s \n",q + 1, Eng[q], Kor[q]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		}
	
		else if (strcmp(cmd, "wrdAdd") == 0) {		// no header

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("\n\"0 0\" �Է����� �ܾ �׸� �Է� �� �� �ֽ��ϴ�, ����� \'_\'�� �Է��� �ּ���. \n");

			while (1) {
				wrd++;
				printf("\n\n\"Eng Kor\" �ܾ� �Է� %d. ", wrd);
				scanf("%s %s", Eng[wrd - 1], Kor[wrd - 1]);

				if (Eng[wrd - 1][0] == '0' && Kor[wrd - 1][0] == '0') {
					wrd--;
					printf("\n�Է��� �ܾ� ����: %d, [wrdAdd] ��ɾ�� �� �߰��� �� �ֽ��ϴ�. \n\n", wrd);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				}
			}
		}
		else if (strcmp(cmd, "wrdDelAll") == 0) {	// no header
			for (int q = 0; q < wrd; q++) {
				for (int p = 0; p < 100; p++) {
					Eng[q][p] = 0;
					Kor[q][p] = 0;
				}
			}

			wrd = 0;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			printf("\n\"0 0\" �Է����� �ܾ �׸� �Է� �� �� �ֽ��ϴ�, ����� \'_\'�� �Է��� �ּ���. \n");

			while (1) {
				wrd++;
				printf("\n\n\"Eng Kor\" �ܾ� �Է� %d. ", wrd);
				scanf("%s %s", Eng[wrd - 1], Kor[wrd - 1]);

				if (Eng[wrd - 1][0] == '0' && Kor[wrd - 1][0] == '0') {
					wrd--;
					printf("\n�Է��� �ܾ� ����: %d, [wrdAdd] ��ɾ�� �� �߰��� �� �ֽ��ϴ�. \n\n", wrd);

					if (wrd == 0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

						printf("\n�߰��� �ܾ �����ϴ�. 3�� �� �ڵ����� ���α׷��� �����մϴ�. \n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

						Sleep(3000);
						return;
					}

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				}
			}
		}
		else if (strcmp(cmd, "wrdDelPrt") == 0) {	// no header
			int prt = 0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			printf("\n�����ϰ� ���� �ܾ��� ��ȣ�� �Է��� �ּ���. \n> ");
			scanf("%d", &prt);

			for (int q = 0; q < 100; q++) {
				Eng[prt - 1][q] = 0;
				Kor[prt - 1][q] = 0;
			}
			wrd--;

			for (int q = prt; q <= wrd; q++) {
				for (int p = 0; p < 100; p++) {
					Eng[q - 1][p] = Eng[q][p];
					Kor[q - 1][p] = Kor[q][p];
				}
			}

			printf("\n%d�� �ܾ ���������� �����߽��ϴ�. \n", prt);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*=== ���� �� ��Ÿ ===*/	// prgmFnsh = ���α׷� ����, DEL = ȭ�� �����, VerChk = ���� üũ, mail = ������ ����, GitHub = ����� C-Language ��ũ, Link = ������ SNS, credits = ���ۿ� ������ �ֽ� �е�
		else if (strcmp(cmd, "prgmFnsh") == 0 || strcmp(cmd, "PF") == 0) {	// no header
			return;
		}
		else if (strcmp(cmd, "DEL") == 0) {			// no header
			system("cls");		// �ܼ� ȭ�� �ʱ�ȭ
		}
		else if (strcmp(cmd, "VerChk") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("\nVer 1.0 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "mail") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("\nmail: dnil4@naver.com \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "GitHub") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("\nGitHub: https://github.com/BOLLT44/C-Language \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "Link") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("\nTistory:    https://bollt.tistory.com/ \nYouTube:    https://www.youtube.com/channel/UCA-5RGnzDV2rskwBk241u3A \n");
			printf("Twitch:     https://www.twitch.tv/bollt40\nTwitter:    https://twitter.com/BOLLT44 \nDiscord:    https://discord.com/invite/35hGybhC2Y \n");
			printf("Naver Blog: https://blog.naver.com/dnil4 \nNaver Post: https://post.naver.com/my.naver?isHome=true \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (strcmp(cmd, "credits") == 0) {		// no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			printf("made by: BOLLT(real name X) \n");
			printf("\nThank You!!\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*=== ERROR ===*/
		else {		//no header
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("\n��ɾ �ν����� ���߽��ϴ�. - ��ɾ ��Ÿ�� �ִ��� Ȯ���ϼ���. / �����ϴ� ��ɾ����� Ȯ���ϼ���. / ������ ������ �˷��ּ���. [mail] ��ɾ �Է��Ͽ� �������� ������ Ȯ�� �� �� �ֽ��ϴ�.\n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

		/*====================*/
	}

	return;
}