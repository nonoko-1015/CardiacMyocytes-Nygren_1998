
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_INaAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_INaAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, R );
    PROPERTYSLOT_SET_GET( Real, P_Na );
    PROPERTYSLOT_SET_GET( Real, T );
    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998_INaAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, R );
  SIMPLE_SET_GET_METHOD( Real, P_Na );
  SIMPLE_SET_GET_METHOD( Real, T );
  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    i_Na  = getVariableReference( "i_Na" ).getVariable();
    m  = getVariableReference( "m" ).getVariable();
    h1  = getVariableReference( "h1" ).getVariable();
    h2  = getVariableReference( "h2" ).getVariable();
    Na_c  = getVariableReference( "Na_c" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_Na  = getVariableReference( "E_Na" ).getVariable();
    m_infinity  = getVariableReference( "m_infinity" ).getVariable();
    tau_m  = getVariableReference( "tau_m" ).getVariable();
    h_infinity  = getVariableReference( "h_infinity" ).getVariable();
    tau_h1  = getVariableReference( "tau_h1" ).getVariable();
    tau_h2  = getVariableReference( "tau_h2" ).getVariable();

  }

  virtual void fire()
  {
    v = V->getValue();
    i_Na->setValue( (((P_Na*(pow(m->getValue(), 3.00000))*(0.900000*h1->getValue()+0.100000*h2->getValue())*(Na_c->getMolarConc()*1000)*v*(pow(F, 2.00000)))/(R*T))*(exp(((v-E_Na->getValue())*F)/(R*T))-1.00000))/(exp((v*F)/(R*T))-1.00000) );
    m_infinity->setValue( 1.00000/(1.00000+exp((v+27.1200)/-8.21000)) );
    tau_m->setValue( 4.20000e-05*exp(-(pow((v+25.5700)/28.8000, 2.00000)))+2.40000e-05 );
    h_infinity->setValue( 1.00000/(1.00000+exp((v+63.6000)/5.30000)) );
    tau_h1->setValue( 0.0300000/(1.00000+exp((v+35.1000)/3.20000))+0.000300000 );
    tau_h2->setValue( 0.120000/(1.00000+exp((v+35.1000)/3.20000))+0.00300000 );

  }

 protected:

  Variable* i_Na;
  Variable* m;
  Variable* h1;
  Variable* h2;
  Variable* Na_c;
  Variable* V;
  Variable* E_Na;
  Variable* m_infinity;
  Variable* tau_m;
  Variable* h_infinity;
  Variable* tau_h1;
  Variable* tau_h2;

  Real R;
  Real P_Na;
  Real T;
  Real F;
  Real v;
};

LIBECS_DM_INIT( Nygren_1998_INaAssignmentProcess, Process );
