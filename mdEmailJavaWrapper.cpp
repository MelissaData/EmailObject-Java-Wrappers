#include <jni.h>

#include "mdEmail.h"

class Utf8String {
	private:
		JNIEnv* env;
		const char* utf8Ptr;
		jstring jString;
	public:
		Utf8String(JNIEnv* jEnv,jstring str);
		~Utf8String();
		const char* GetUtf8Ptr();
};

Utf8String::Utf8String(JNIEnv* jEnv,jstring str) {
	env=jEnv;
	jString=str;
	if (jString!=0)
		utf8Ptr=env->GetStringUTFChars(jString,0);
	else
		utf8Ptr=0;
}

Utf8String::~Utf8String() {
	if (utf8Ptr!=0)
		env->ReleaseStringUTFChars(jString,utf8Ptr);
}

const char* Utf8String::GetUtf8Ptr() {
	if (utf8Ptr!=0)
		return utf8Ptr;
	return "";
}

jstring UnicodeString(JNIEnv* jEnv,const char* str) {
	if (str!=0)
		return jEnv->NewStringUTF(str);
	return jEnv->NewStringUTF("");
}

extern "C" JNIEXPORT jlong JNICALL Java_com_melissadata_mdEmailJNI_mdEmailCreate(JNIEnv* /*jEnv*/,jclass /*jCls*/) {
	return (jlong) new mdEmail();
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_mdEmailDestroy(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	delete (mdEmail*) I;
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdEmailJNI_SetLicenseString(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring License) {
	Utf8String _License(jEnv,License);
	return (jboolean) ((mdEmail*) I)->SetLicenseString(_License.GetUtf8Ptr());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetPathToEmailFiles(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring emailDataFiles) {
	Utf8String _emailDataFiles(jEnv,emailDataFiles);
	((mdEmail*) I)->SetPathToEmailFiles(_emailDataFiles.GetUtf8Ptr());
}

extern "C" JNIEXPORT jint JNICALL Java_com_melissadata_mdEmailJNI_InitializeDataFiles(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jint) ((mdEmail*) I)->InitializeDataFiles();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetInitializeErrorString(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetInitializeErrorString());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetBuildNumber(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetBuildNumber());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetDatabaseDate(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetDatabaseDate());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetDatabaseExpirationDate(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetDatabaseExpirationDate());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetLicenseStringExpirationDate(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetLicenseStringExpirationDate());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_melissadata_mdEmailJNI_VerifyEmail(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring email) {
	Utf8String _email(jEnv,email);
	return (jboolean) ((mdEmail*) I)->VerifyEmail(_email.GetUtf8Ptr());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetCorrectSyntax(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdEmail*) I)->SetCorrectSyntax(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetUpdateDomain(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdEmail*) I)->SetUpdateDomain(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetDatabaseLookup(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdEmail*) I)->SetDatabaseLookup(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetFuzzyLookup(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdEmail*) I)->SetFuzzyLookup(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetWSLookup(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdEmail*) I)->SetWSLookup(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetWSMailboxLookup(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jint mailboxLookupmode) {
	((mdEmail*) I)->SetWSMailboxLookup((mdEmail::MailboxLookupMode) mailboxLookupmode);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetMXLookup(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdEmail*) I)->SetMXLookup(p1!=0 ? true : false);
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetStandardizeCasing(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jboolean p1) {
	((mdEmail*) I)->SetStandardizeCasing(p1!=0 ? true : false);
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetStatusCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetStatusCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetErrorCode(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetErrorCode());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetErrorString(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetErrorString());
}

extern "C" JNIEXPORT jlong JNICALL Java_com_melissadata_mdEmailJNI_GetChangeCode(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I) {
	return (jlong) ((mdEmail*) I)->GetChangeCode();
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetResults(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetResults());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetResultCodeDescription(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring resultCode,jint opt) {
	Utf8String _resultCode(jEnv,resultCode);
	return UnicodeString(jEnv,((mdEmail*) I)->GetResultCodeDescription(_resultCode.GetUtf8Ptr(),(mdEmail::ResultCdDescOpt) opt));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetMailBoxName(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetMailBoxName());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetDomainName(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetDomainName());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetTopLevelDomain(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetTopLevelDomain());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetTopLevelDomainDescription(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetTopLevelDomainDescription());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetEmailAddress(JNIEnv* jEnv,jclass /*jCls*/,jlong I) {
	return UnicodeString(jEnv,((mdEmail*) I)->GetEmailAddress());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetReserved(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring Property,jstring Value_) {
	Utf8String _Property(jEnv,Property);
	Utf8String _Value_(jEnv,Value_);
	((mdEmail*) I)->SetReserved(_Property.GetUtf8Ptr(),_Value_.GetUtf8Ptr());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_melissadata_mdEmailJNI_GetReserved(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring Property_) {
	Utf8String _Property_(jEnv,Property_);
	return UnicodeString(jEnv,((mdEmail*) I)->GetReserved(_Property_.GetUtf8Ptr()));
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetCachePath(JNIEnv* jEnv,jclass /*jCls*/,jlong I,jstring cachePath) {
	Utf8String _cachePath(jEnv,cachePath);
	((mdEmail*) I)->SetCachePath(_cachePath.GetUtf8Ptr());
}

extern "C" JNIEXPORT void JNICALL Java_com_melissadata_mdEmailJNI_SetCacheUse(JNIEnv* /*jEnv*/,jclass /*jCls*/,jlong I,jint cacheUse) {
	((mdEmail*) I)->SetCacheUse((int) cacheUse);
}

