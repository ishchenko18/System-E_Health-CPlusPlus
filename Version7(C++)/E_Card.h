#if !defined(__E_Mediciana_E_Card_h)
#define __E_Mediciana_E_Card_h
#include <string>
#include <vector>

using namespace std;

/*!
\brief ���� ����� �������� ������ ��������� ����������� �� ��� ������ ���������\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class E_Card
{
public:
   void Write(void);///<����� ������� �� ��������� ����� �� ���������� ������
   void Read(void);///<����� ������� �� �������� �����, �� ������ ���������� ������
   void Change(void);///<����� ������� �� ���� ����� � ���������� ������
   
   /*!
   \return ������� ������� ������ �����
   */
   int GetSizeDailyPressure();///<����� ������� �� ��������� ������� ������� ������ �����

   /*!
   \return ������� ������� ����� �����
   */
   int GetSizeNightPressure();///<����� ������� �� ��������� ������� ������� ����� �����

   /*!
   \return ������� ������� ������ ������
   */
   int GetSizeDailyPulse();///<����� ������� �� ��������� ������� ������� ������ ������

   /*!
   \return ������� ������� ����� ������
   */
   int GetSizeNightPulse();///<����� ������� �� ��������� ������� ������� ����� ������

   /*!
   \return ������� ������� ���������� ������������
   */
   int GetSizeEncephalograph();///<����� ������� �� ��������� ������� ������� ������������

   /*!
   \return ������� ������� ���������� ��������� ������ ����
   */
   int GetSizeUrinalysis();///<����� ������� �� ��������� ������� ������� ��������� ������ ����

   /*!
   \return ������� ������� ���������� ���������
   */
   int GetSizeCaplogramme();///<����� ������� �� ��������� ������� ������� ����������
   int GetAge();///<����� ��� ��� �����������
   /*!
   \param age �� �����������
   */
   void SetAge(int age);///<����� ��� ��� �����������
   int GetLastVisit();///<����� ��� ���������� ��������� ������
   /*!
   \param lastvisit �-�� ������ � ���� ���������� ����������
   */
   void SetLastVisit(int lastvisit);///<����� ��� ���������� ��������� ������
   int GetGroupOfBlood();///<����� ��� ����� ���� �����������
   /*!
   \param groupBlood ����� ���� �����������
   */
   void SetGroupOfBlood(int groupBlood);///<����� ��� ����� ���� �����������
   char GetRh();///<����� ��� �����-������� �����������
   /*!
   \param rh �����-������ �����������
   */
   void SetRh(char rh);///<����� ��� �����-������� �����������
   float GetWeight();///<����� ��� ���� �����������
   /*!
   \param weight ���� �����������
   */
   void SetWeight(float weight);///<����� ��� ���� �����������
   float GetHeight();///<����� ��� ������ �����������
   /*!
   \param height ���� �����������
   */
   void SetHeight(float height);///<����� ��� ������ �����������
   string GetSex();///<����� ��� ���� �����������
   /*!
   \param sex ����� �����������
   */
   void SetSex(string sex);///<����� ��� ���� �����������
   /*!
   \param result ������� ��������� ����������
   \param index ������ �������� ������
   */
   void SetBadresults(bool result, int index);///<����� ��� ���������� ������ �����������
   /*!
   \param index ������ �������� �������
   */
   bool GetBadresults(int index);///<����� ��� ���������� ������ �����������
   void GetChronicIllnes();///<����� ��� �������� ����������� �����������
   /*!
   \param ill ������� ������������
   */
   void SetChroniIllnes(string ill);///<����� ��� �������� ����������� �����������
   /*!
   \param index ������ �������� �������
   */
   int GetDailyPressure(int index);///<����� ��� ������� ����� �����������
   /*!
   \param pressure ������ ����
   */
   void SetDailyPressure(int pressure);///<����� ��� ������� ����� �����������
   /*!
   \param index ������ �������� �������
   */
   int GetDailyPulse(int index);///<����� ��� ������� ������ �����������
   /*!
   \param pulse ������ �����
   */
   void SetDailyPulse(int pulse);///<����� ��� ������� ������ �����������
   /*!
   \param index ������ �������� �������
   */
   int GetNightPressure(int index);///<����� ��� ������ ����� �����������
   /*!
   \param pressure ����� ����
   */
   void SetNightPressure(int pressure);///<����� ��� ������ ����� �����������
   /*!
   \param index ������ �������� �������
   */
   int GetNightPulse(int index);///<����� ��� ������ ������ �����������
   /*!
   \param pulse ����� �����
   */
   void SetNightPulse(int pulse);///<����� ��� ������ ������ �����������
   /*!
   \param index ������ �������� �������
   */
   bool GetEncelograph(int index);///<����� ��� ����������� �����������
   /*!
   \param encelograph ��������� ������������
   */
   void SetEncelograph(bool encelograph);///<����� ��� ����������� �����������
   /*!
   \param index ������ �������� �������
   */
   float GetKaplograms(int index);///<����� ��� ����������� �����������
   /*!
   \param kaplogram ��������� �����������
   */
   void SetKaplogram(float kaplogram);///<����� ��� ������������ �����������
   /*!
   \param index ������ �������� �������
   */
   float GetUrinalysis(int index);///<����� ��� ��� �����������
   /*! 
   \param urinalys ��������� ���
   */
   void SetUrinalys(float urinalys);///<����� ��� ��� �����������
   void GetDiagnosis();///<����� ��� ������� �����������
   /*!
   \param diagnos ������
   */
   void SetDiagnos(string diagnos);///<����� ��� ������� �����������
   void GetAppointments();///<����� ��� ���������� �����������
   /*!
   \param appointment ����������� �����
   */
   void SetAppointment(string appointment);///<����� ��� ���������� �����������
   void GetResultsOfSurvey();///<����� ��� ���������� ��������� �����������
   /*!
   \param resultsurvey ��������� ��������� ������
   */
   void SetResultOfSurvey(string resultsurvey);///<����� ��� ���������� ��������� �����������
   int GetSizeDiagnosis();
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param ��� ���������
   */
   E_Card();///<����������� �� ������������
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param age ��
   \param groupblood ����� ����
   \param _rh �����-������
   \param _weight ����
   \param _height ����
   \param lastvisit �-�� ������ � ���� ���������� �����
   \param _sex �����
   \param _chronicIll ������ �������� �����������
   \param pressurenight ������ ������ �����
   \param pressureday ������ ������� �����
   \param pulsenight ������ ������ ������
   \param pulseday ������ ������� ������
   \param encelogra ��������� �����������
   \param kaplo ������ ���������� ����������
   \param urinal ������ ���������� ������ ����
   \param diagnos ������ �������
   \param appoint ������ ����������
   \param resultsurv ������ ���������� ����������
   */
   E_Card(int _age, int groupblood, char _rh, float _weight, float _height, int lastvisit, string _sex, vector <string>  _chronicIll, vector <int> pressurenight, vector <int> pressureday,
	   vector <int> pulsenight, vector <int> pulseday, vector <bool> encelogra, vector <float> kaplo, vector <float> urinal, vector <string> diagnos, vector <string> appoint, vector <string> resultsurv);///<K���������� ������������
   /*!
   ��������� �����������, �� ���������� ���������
   \param ��� ���������
   */
   ~E_Card();///<����������

protected:
private:
   int age;///<³� 
   int groupOfBlood;///<����� ����
   char rh;///<�����-������
   float weight;///<���� �����������
   float height;///<���� �����������
   int lastvisit; ///<�-�� ������ � ���� ���������� ����������
   string sex;///<����� �����������
   vector <string> chronicIllness;///<������ �������� ����������� ����������� �� ���� ������
   bool badresults[7];///<����� ��� ���������� ���������� ������ � ������ ����( 1 - ������ ���� 2 - ����� ����
					  ///<3 -������ ����� 4 - ����� ����� 5 - ������������� 6 - ����������� 7 - ����� ����
   vector <int> dailypressure;///<������ ������� �����
   vector <int> nightpressure;///<������ ������ �����
   vector <int> dailypulse;///<������ ������� ������
   vector <int> nightpulse;///<������ ������ ������
   vector <bool> encelograph;///<������ ���������� �������������
   vector <float> kaplogram;///<������ ���������� ����������
   vector <float> urinalysis;///<������ ���������� ������ ����
   vector <string> diagnosis;///<������ �������
   vector <string> appointment;///<������ ����������
   vector <string> resultofsurvey;///<������ ���������� ������

};

#endif