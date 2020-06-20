
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_upAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_upAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, k_cyca );
    PROPERTYSLOT_SET_GET( Real, k_xcs );
    PROPERTYSLOT_SET_GET( Real, I_up_max );
    PROPERTYSLOT_SET_GET( Real, k_srca );

  }

  Nygren_1998i_upAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, k_cyca );
  SIMPLE_SET_GET_METHOD( Real, k_xcs );
  SIMPLE_SET_GET_METHOD( Real, I_up_max );
  SIMPLE_SET_GET_METHOD( Real, k_srca );


  virtual void initialize()
  {
    Process::initialize();

    i_up  = getVariableReference( "i_up" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();
    Ca_up  = getVariableReference( "Ca_up" ).getVariable();

  }

  virtual void fire()
  {
    i_up->setValue( 1 * ((I_up_max*((Ca_i->getMolarConc()*1000)/k_cyca-((pow(k_xcs, 2.00000))*(Ca_up->getMolarConc()*1000))/k_srca))/(((Ca_i->getMolarConc()*1000)+k_cyca)/k_cyca+(k_xcs*((Ca_up->getMolarConc()*1000)+k_srca))/k_srca)) );

  }

 protected:

  Variable* i_up;
  Variable* Ca_i;
  Variable* Ca_up;

  Real k_cyca;
  Real k_xcs;
  Real I_up_max;
  Real k_srca;

};

LIBECS_DM_INIT( Nygren_1998i_upAssignmentProcess, Process );
