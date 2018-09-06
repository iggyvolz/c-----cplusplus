#define OPIMP_FUNC(x) void OPIMP_##x(void*,void*,void**); \
*(currOpimp++)=OPIMP_##x; \
void OPIMP_##x(void* first, void* second, void** ret)
void (*opimps[24])();
void (**currOpimp)()=opimps;
OPIMP_FUNC(SecondString){
    // Return the second as a string
    *ret=(void*)new std::string(*(string*)second);
}
OPIMP_FUNC(ConcOneAndTwo){
    // Return the first and second concatenated
    *ret=(void*)new std::string((*(string*)first)+(*(string*)second));
}