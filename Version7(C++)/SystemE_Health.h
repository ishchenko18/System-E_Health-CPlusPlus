
#if !defined(__E_Mediciana_SystemE_Health_h)
#define __E_Mediciana_SystemE_Health_h
#include <vector>
#include <string>

class SmartBed;
class SmartBracelet;
class SmartToilet;
class E_Card;

/*!
\brief ���� ������� �� ������� �������� ����������
\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class SystemE_Health
{
public:
	/*!
	\return ������������, ��� ����������� ������� �������� �����
	*/
   std::string InvitationToDoctor(void);///<����� ������� �� ���������  ������������, ���� ����������� �'������� �� �����
   /*!
   \return ������������, ���� ��������
   */
   std::string RecomendationOfTreatment();///<����� ������� �� ��������� ������������, ���� ��������
   /*!
   \return ������, ���� ������ � ���� ��� ������� � ������ �������
   */
   bool Compare(void);///<����� ������� ���������� ������ � ��������
   /*!
   \return ���������� �� �������� �����
   */
   std::string SendInvation(void);///<����� ������� �� ���������� ��������� �� ����������
   /*!
   \param resultsurvey ��������� ����������
   */
   void ResultsOfSurvey(string resultsurvey);///<����� ������� �� ����������� ���������� ����������
   void DataInCard(void);///<����� ������� �� ��������� ����� �� ���������� ������
   void GetEtalon();///<����� �������� ������� ���������� ������ ������������
   void SetEtalon();///<������������ ��������� �������
   
   /*!
   \return ������� ��������� ��������� ������� ����� � ��������
   \param index ������ �������� ������� � ����
   */
   bool CompareDailyPressure(int index);///<��������� ������� ����� � ��������
  
   /*!
   \return ������� ��������� ��������� ������ ����� � ��������
   \param index ������ �������� ������� � ����
   */
   bool CompareNightPressure(int index);///<��������� ������ ����� � ��������
   
   /*!
   \return ������� ��������� ��������� ������� ������ � ��������
   \param index ������ �������� ������� � ����
   */
   bool CompareDailyPulse(int index);///<��������� ������� ������ � ��������
  
   /*!
   \return ������� ��������� ��������� ������ ����� � ��������
   \param index ������ �������� ������� � ����
   */
   bool CompareNightPulse(int index);///<��������� ������ ����� � ��������
   
   /*!
   \return ������� ��������� ��������� ������������� � ��������
   \param index ������ �������� ������� � ����
   */
   bool CompareEncephalogram(int index);///<��������� ������������� � ��������
   
   /*!
   \return ������� ��������� ��������� ���������� ������ ���� � ��������
   \param index ������ �������� ������� � ����
   */
   bool CompareUrinalysis(int index);///<��������� ���������� ������ ���� � ��������
   
   /*!
   \return ������� ��������� ��������� ���������� � ��������
   \param index ������ �������� ������� � ����
   */
   bool CompareCaplogramme(int index);///<��������� ���������� � ��������

   /*!
   \return ������� ��������� ��������� 
   \param obj - ��*��� ����� SystemE_Health
   \param month - �-�� ������ ��� ���������
   */
   bool operator == (int month);///<�������������� ��������� ���������

   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param ��� ���������
   */
   SystemE_Health();///<����������� �� ������������
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param engraphy ��������� ������������
   \param etal ������ ��������� ������� ���������� ������
   \param invit ����� ���������� �� �����
   \param recom ����� ������������
   */
   SystemE_Health(vector <float> etal, string recom);///<����������� ������������
   /*!
   ��������� �����������, �� ���������� ���������
   \param ��� ���������
   */
   ~SystemE_Health();///<����������

   vector<E_Card> cards;///<������ ��'����
   vector<SmartToilet> toilet;///<������ ��'����
   vector<SmartBracelet> bracelet;///<������ ��'����
   vector<SmartBed> bed;///<������ ��'����

protected:
private:
   vector<float> etalon;///<������ � ���������� ���������� ������
   std::string recomendation;///<����� ������������
   std::string invitationToDoctor="You need in undergo medical examination in your treatment doctor";///<����� ���������� �� �����
   std::string invitationToClinic="You need in undergo medical examination in your clinic";///<����� ���������� �� �����

};

#endif