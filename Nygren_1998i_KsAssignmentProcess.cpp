
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_KsAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_KsAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_Ks );

  }

  Nygren_1998i_KsAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_Ks );


  virtual void initialize()
  {
    Process::initialize();

    i_Ks  = getVariableReference( "i_Ks" ).getVariable();
    n  = getVariableReference( "n" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_K  = getVariableReference( "E_K" ).getVariable();

  }

  virtual void fire()
  {
    i_Ks->setValue( 1 * (g_Ks*n->getValue()*(V->getValue()-E_K->getValue())) );

  }

 protected:

  Variable* i_Ks;
  Variable* n;
  Variable* V;
  Variable* E_K;

  Real g_Ks;

};

LIBECS_DM_INIT( Nygren_1998i_KsAssignmentProcess, Process );
