// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

/**
 * @file
 * @brief Generated from world_event_mission_phase_table.xsd.
 */

#ifndef GDT_WORLD_EVENT_MISSION_PHASE_TABLE_HXX
#define GDT_WORLD_EVENT_MISSION_PHASE_TABLE_HXX

// Begin prologue.
//
#include "shared_types.hxx"
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3030000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#ifndef XSD_USE_WCHAR
#define XSD_USE_WCHAR
#endif

#ifndef XSD_CXX_TREE_USE_WCHAR
#define XSD_CXX_TREE_USE_WCHAR
#endif

#include "xml_schema.hxx"

// Forward declarations.
//
namespace gdt
{
  class world_event_mission_phase_t;
  class world_event_mission_phase_table;
}


#include <memory>    // std::auto_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#ifndef XSD_DONT_INCLUDE_INLINE
#define XSD_DONT_INCLUDE_INLINE

#include "shared_types.hxx"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "shared_types.hxx"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %
 * schema namespace.
 */
namespace gdt
{
  /**
   * @brief Class corresponding to the %world_event_mission_phase_t schema type.
   *
   * @nosubgrouping
   */
  class GIDEON_CS_API world_event_mission_phase_t: public ::xml_schema::type
  {
    public:
    /**
     * @name world_event_code
     *
     * @brief Accessor and modifier functions for the %world_event_code
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::gdt::world_event_code_t world_event_code_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< world_event_code_type, wchar_t > world_event_code_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const world_event_code_type&
    world_event_code () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    world_event_code_type&
    world_event_code ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    world_event_code (const world_event_code_type& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    world_event_code (::std::auto_ptr< world_event_code_type > p);

    //@}

    /**
     * @name mission_phase
     *
     * @brief Accessor and modifier functions for the %mission_phase
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::unsigned_byte mission_phase_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< mission_phase_type, wchar_t > mission_phase_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const mission_phase_type&
    mission_phase () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    mission_phase_type&
    mission_phase ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    mission_phase (const mission_phase_type& x);

    //@}

    /**
     * @name mission_round_count
     *
     * @brief Accessor and modifier functions for the %mission_round_count
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::unsigned_byte mission_round_count_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< mission_round_count_type, wchar_t > mission_round_count_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const mission_round_count_type&
    mission_round_count () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    mission_round_count_type&
    mission_round_count ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    mission_round_count (const mission_round_count_type& x);

    //@}

    /**
     * @name start_region_code
     *
     * @brief Accessor and modifier functions for the %start_region_code
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::gdt::region_code_t start_region_code_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< start_region_code_type, wchar_t > start_region_code_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const start_region_code_type&
    start_region_code () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    start_region_code_type&
    start_region_code ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    start_region_code (const start_region_code_type& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    start_region_code (::std::auto_ptr< start_region_code_type > p);

    //@}

    /**
     * @name reward_cost_type
     *
     * @brief Accessor and modifier functions for the %reward_cost_type
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::gdt::cost_type_t reward_cost_type_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< reward_cost_type_type, wchar_t > reward_cost_type_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const reward_cost_type_type&
    reward_cost_type () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    reward_cost_type_type&
    reward_cost_type ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    reward_cost_type (const reward_cost_type_type& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    reward_cost_type (::std::auto_ptr< reward_cost_type_type > p);

    //@}

    /**
     * @name reward_cost_value
     *
     * @brief Accessor and modifier functions for the %reward_cost_value
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::unsigned_int reward_cost_value_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< reward_cost_value_type, wchar_t > reward_cost_value_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const reward_cost_value_type&
    reward_cost_value () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    reward_cost_value_type&
    reward_cost_value ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    reward_cost_value (const reward_cost_value_type& x);

    //@}

    /**
     * @name should_public_party
     *
     * @brief Accessor and modifier functions for the %should_public_party
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::gdt::bit_t should_public_party_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< should_public_party_type, wchar_t > should_public_party_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const should_public_party_type&
    should_public_party () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    should_public_party_type&
    should_public_party ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    should_public_party (const should_public_party_type& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    should_public_party (::std::auto_ptr< should_public_party_type > p);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Default constructor.
     *
     * Note that this constructor leaves required elements and
     * attributes uninitialized.
     */
    world_event_mission_phase_t ();

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    world_event_mission_phase_t (const world_event_code_type&,
                                 const mission_phase_type&,
                                 const mission_round_count_type&,
                                 const start_region_code_type&,
                                 const reward_cost_type_type&,
                                 const reward_cost_value_type&,
                                 const should_public_party_type&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    world_event_mission_phase_t (const ::xercesc::DOMElement& e,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    world_event_mission_phase_t (const world_event_mission_phase_t& x,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual world_event_mission_phase_t*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~world_event_mission_phase_t ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< wchar_t >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< world_event_code_type > world_event_code_;
    ::xsd::cxx::tree::one< mission_phase_type > mission_phase_;
    ::xsd::cxx::tree::one< mission_round_count_type > mission_round_count_;
    ::xsd::cxx::tree::one< start_region_code_type > start_region_code_;
    ::xsd::cxx::tree::one< reward_cost_type_type > reward_cost_type_;
    ::xsd::cxx::tree::one< reward_cost_value_type > reward_cost_value_;
    ::xsd::cxx::tree::one< should_public_party_type > should_public_party_;

    //@endcond
  };

  /**
   * @brief Class corresponding to the %world_event_mission_phase_table schema type.
   *
   * @nosubgrouping
   */
  class GIDEON_CS_API world_event_mission_phase_table: public ::xml_schema::type
  {
    public:
    /**
     * @name world_event_mission_phase_template
     *
     * @brief Accessor and modifier functions for the %world_event_mission_phase_template
     * sequence element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::gdt::world_event_mission_phase_t world_event_mission_phase_template_type;

    /**
     * @brief Element sequence container type.
     */
    typedef ::xsd::cxx::tree::sequence< world_event_mission_phase_template_type > world_event_mission_phase_template_sequence;

    /**
     * @brief Element iterator type.
     */
    typedef world_event_mission_phase_template_sequence::iterator world_event_mission_phase_template_iterator;

    /**
     * @brief Element constant iterator type.
     */
    typedef world_event_mission_phase_template_sequence::const_iterator world_event_mission_phase_template_const_iterator;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< world_event_mission_phase_template_type, wchar_t > world_event_mission_phase_template_traits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * sequence.
     *
     * @return A constant reference to the sequence container.
     */
    const world_event_mission_phase_template_sequence&
    world_event_mission_phase_template () const;

    /**
     * @brief Return a read-write reference to the element sequence.
     *
     * @return A reference to the sequence container.
     */
    world_event_mission_phase_template_sequence&
    world_event_mission_phase_template ();

    /**
     * @brief Copy elements from a given sequence.
     *
     * @param s A sequence to copy elements from.
     *
     * For each element in @a s this function makes a copy and adds it 
     * to the sequence. Note that this operation completely changes the 
     * sequence and all old elements will be lost.
     */
    void
    world_event_mission_phase_template (const world_event_mission_phase_template_sequence& s);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    world_event_mission_phase_table ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    world_event_mission_phase_table (const ::xercesc::DOMElement& e,
                                     ::xml_schema::flags f = 0,
                                     ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    world_event_mission_phase_table (const world_event_mission_phase_table& x,
                                     ::xml_schema::flags f = 0,
                                     ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual world_event_mission_phase_table*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~world_event_mission_phase_table ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< wchar_t >&,
           ::xml_schema::flags);

    protected:
    world_event_mission_phase_template_sequence world_event_mission_phase_template_;

    //@endcond
  };
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "shared_types.ixx"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace gdt
{
  /**
   * @name Parsing functions for the %world_event_mission_phase_table document root.
   */
  //@{

  /**
   * @brief Parse a URI or a local file.
   *
   * @param uri A URI or a local file name.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (const ::std::wstring& uri,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a URI or a local file with an error handler.
   *
   * @param uri A URI or a local file name.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (const ::std::wstring& uri,
                                    ::xml_schema::error_handler& eh,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a URI or a local file with a Xerces-C++ DOM error
   * handler.
   *
   * @param uri A URI or a local file name.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (const ::std::wstring& uri,
                                    ::xercesc::DOMErrorHandler& eh,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream.
   *
   * @param is A standrad input stream.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::std::istream& is,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with an error handler.
   *
   * @param is A standrad input stream.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::std::istream& is,
                                    ::xml_schema::error_handler& eh,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a Xerces-C++ DOM error
   * handler.
   *
   * @param is A standrad input stream.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::std::istream& is,
                                    ::xercesc::DOMErrorHandler& eh,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::std::istream& is,
                                    const ::std::wstring& id,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id and an
   * error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::std::istream& is,
                                    const ::std::wstring& id,
                                    ::xml_schema::error_handler& eh,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id and a
   * Xerces-C++ DOM error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::std::istream& is,
                                    const ::std::wstring& id,
                                    ::xercesc::DOMErrorHandler& eh,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source.
   *
   * @param is A Xerces-C++ input source.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::xercesc::InputSource& is,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source with an error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::xercesc::InputSource& is,
                                    ::xml_schema::error_handler& eh,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source with a Xerces-C++ DOM
   * error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::xercesc::InputSource& is,
                                    ::xercesc::DOMErrorHandler& eh,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (const ::xercesc::DOMDocument& d,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A pointer to the Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function is normally used together with the keep_dom and
   * own_dom parsing flags to assign ownership of the DOM document
   * to the object model.
   */
  GIDEON_CS_API
  ::std::auto_ptr< ::gdt::world_event_mission_phase_table >
  world_event_mission_phase_table_ (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
                                    ::xml_schema::flags f = 0,
                                    const ::xml_schema::properties& p = ::xml_schema::properties ());

  //@}
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace gdt
{
  /**
   * @name Serialization functions for the %world_event_mission_phase_table document root.
   */
  //@{

  /**
   * @brief Serialize to a standard output stream.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  GIDEON_CS_API
  void
  world_event_mission_phase_table_ (::std::ostream& os,
                                    const ::gdt::world_event_mission_phase_table& x, 
                                    const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                                    const ::std::wstring& e = L"UTF-8",
                                    ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a standard output stream with an error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  world_event_mission_phase_table_ (::std::ostream& os,
                                    const ::gdt::world_event_mission_phase_table& x, 
                                    ::xml_schema::error_handler& eh,
                                    const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                                    const ::std::wstring& e = L"UTF-8",
                                    ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a standard output stream with a Xerces-C++ DOM
   * error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  world_event_mission_phase_table_ (::std::ostream& os,
                                    const ::gdt::world_event_mission_phase_table& x, 
                                    ::xercesc::DOMErrorHandler& eh,
                                    const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                                    const ::std::wstring& e = L"UTF-8",
                                    ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  GIDEON_CS_API
  void
  world_event_mission_phase_table_ (::xercesc::XMLFormatTarget& ft,
                                    const ::gdt::world_event_mission_phase_table& x, 
                                    const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                                    const ::std::wstring& e = L"UTF-8",
                                    ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with an error
   * handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  world_event_mission_phase_table_ (::xercesc::XMLFormatTarget& ft,
                                    const ::gdt::world_event_mission_phase_table& x, 
                                    ::xml_schema::error_handler& eh,
                                    const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                                    const ::std::wstring& e = L"UTF-8",
                                    ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with a
   * Xerces-C++ DOM error handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  world_event_mission_phase_table_ (::xercesc::XMLFormatTarget& ft,
                                    const ::gdt::world_event_mission_phase_table& x, 
                                    ::xercesc::DOMErrorHandler& eh,
                                    const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                                    const ::std::wstring& e = L"UTF-8",
                                    ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to an existing Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param x An object model to serialize.
   * @param f Serialization flags.
   *
   * Note that it is your responsibility to create the DOM document
   * with the correct root element as well as set the necessary
   * namespace mapping attributes.
   */
  GIDEON_CS_API
  void
  world_event_mission_phase_table_ (::xercesc::DOMDocument& d,
                                    const ::gdt::world_event_mission_phase_table& x,
                                    ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a new Xerces-C++ DOM document.
   *
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param f Serialization flags.
   * @return A pointer to the new Xerces-C++ DOM document.
   */
  GIDEON_CS_API
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
  world_event_mission_phase_table_ (const ::gdt::world_event_mission_phase_table& x, 
                                    const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                                    ::xml_schema::flags f = 0);

  //@}

  GIDEON_CS_API
  void
  operator<< (::xercesc::DOMElement&, const world_event_mission_phase_t&);

  GIDEON_CS_API
  void
  operator<< (::xercesc::DOMElement&, const world_event_mission_phase_table&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "world_event_mission_phase_table.ixx"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_WORLD_EVENT_MISSION_PHASE_TABLE_HXX
