
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_NaKAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_NaKAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, i_NaK_max );
    PROPERTYSLOT_SET_GET( Real, k_NaK_Na );
    PROPERTYSLOT_SET_GET( Real, k_NaK_K );

  }

  Nygren_1998i_NaKAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, i_NaK_max );
  SIMPLE_SET_GET_METHOD( Real, k_NaK_Na );
  SIMPLE_SET_GET_METHOD( Real, k_NaK_K );


  virtual void initialize()
  {
    Process::initialize();

    i_NaK  = getVariableReference( "i_NaK" ).getVariable();
    K_c  = getVariableReference( "K_c" ).getVariable();
    Na_i  = getVariableReference( "Na_i" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    i_NaK->setValue( 1 * ((((((i_NaK_max*(K_c->getMolarConc()*1000))/((K_c->getMolarConc()*1000)+k_NaK_K))*(pow((Na_i->getMolarConc()*1000), 1.50000)))/(pow((Na_i->getMolarConc()*1000), 1.50000)+pow(k_NaK_Na, 1.50000)))*(V->getValue()+150.000))/(V->getValue()+200.000)) );

  }

 protected:

  Variable* i_NaK;
  Variable* K_c;
  Variable* Na_i;
  Variable* V;

  Real i_NaK_max;
  Real k_NaK_Na;
  Real k_NaK_K;

};

LIBECS_DM_INIT( Nygren_1998i_NaKAssignmentProcess, Process );
